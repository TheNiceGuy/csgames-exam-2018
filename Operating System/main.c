/////////////////////////////////
// NE TOUCHEZ PAS À CE FICHIER //
/////////////////////////////////

#include <argp.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <solve.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/** The description of this program. */
static char description[] = "Simple program that solves Laplace's equations.";

#define SOCKET_FILE_KEY  's'
#define LOG_FILE_KEY      'l'
#define START_DAEMON_KEY 0x400
#define STOP_DAEMON_KEY  0x500
#define THREAD_COUNT_KEY 0x600

/** The option configurations for this program. */
static struct argp_option options[] = {
    {
        .name = "socket",
        .key = SOCKET_FILE_KEY,
        .arg = "FILE",
        .flags = 0,
        .doc = "The path to the socket of the daemon."
    }, {
        .name = "log",
        .key = LOG_FILE_KEY,
        .arg = "FILE",
        .flags = 0,
        .doc = "The log file when the application is running in background."
    }, {
        .name = "start",
        .key = START_DAEMON_KEY,
        .arg = 0,
        .flags = 0,
        .doc = "Start the application in background."
    }, {
        .name = "stop",
        .key = STOP_DAEMON_KEY,
        .arg = 0,
        .flags = 0,
        .doc = "Stop the application in background."
    }, {
        .name = "threads",
        .key = THREAD_COUNT_KEY,
        .arg = "COUNT",
        .flags = 0,
        .doc = "The number of threads for solving the problems."
    }, {
        0
    },
};

/** Arguments that can be modified using command line options. */
struct arguments {
    /** The socket used by the daemon. */
    char* socket;

    /** The log file when running in daemon. */
    char* log;

    /** Whether to start the daemon. */
    uint8_t start_daemon : 1;

    /** Whether to stop the daemon. */
    uint8_t stop_daemon : 1;

    /** The number of threads for solving the problems. */
    int threads;
};

/**
 * This function parses options from the command line.
 */
static error_t parse_arg(int key, char *arg, struct argp_state *state) {
    /* get the arguments' configuration */
    struct arguments *arguments = state->input;

    /* get the current option */
    char* option = state->argv[state->next-1];

    /* parse the key */
    void* addr;
    switch(key) {
        /* daemon socket */
        case SOCKET_FILE_KEY:
            if(arg == NULL) {
                argp_error(state, "socket not specified with `%s`", option);
                return ARGP_ERR_UNKNOWN;
            }

            arguments->socket = arg;
            break;

        /* log file */
        case LOG_FILE_KEY:
            if(arg == NULL) {
                argp_error(state, "log file not specified with `%s`", option);
                return ARGP_ERR_UNKNOWN;
            }

            arguments->log = arg;
            break;

        /* start daemon */
        case START_DAEMON_KEY:
            /* we can't start and stop at the same time */
            if(arguments->stop_daemon) {
                argp_error(state, "`--stop` already specified with `%s`", option);
                return ARGP_ERR_UNKNOWN;
            }

            arguments->start_daemon = 1;
            break;

        /* stop daemon */
        case STOP_DAEMON_KEY:
            /* we can't start and stop at the same time */
            if(arguments->start_daemon) {
                argp_error(state, "`--start` already specified with `%s`", option);
                return ARGP_ERR_UNKNOWN;
            }

            arguments->stop_daemon = 1;
            break;

        /* number of threads */
        case THREAD_COUNT_KEY:
            if(arg == NULL) {
                argp_error(state, "number not specified with `%s`", option);
                return ARGP_ERR_UNKNOWN;
            }

            /* make sure the input is a number */
            errno = 0;
            arguments->threads = strtol(arg, NULL, 10);
            if(errno != 0) {
                argp_error(state, "`%s` is not a valid number", option);
                return ARGP_ERR_UNKNOWN;
            }

            /* make sure the number of threads is valid */
            if(arguments->threads < 1) {
                argp_error(state, "`%s` is not a valid number", option);
                arguments->threads = 1;
                return ARGP_ERR_UNKNOWN;
            }
            break;

        /* keyword arguments */
        case ARGP_KEY_ARG:

        /* unknown argument */
        default:
            return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

/**
 * This function sets the default parameters of the program.
 */
static void set_default_params(struct arguments* arguments) {
    /* by default, use a socket in /tmp/ */
    arguments->socket = "/tmp/laplace.socket";

    /* by default, use a file in /tmp/ */
    arguments->log = "/tmp/laplace.log";

    /* by default, don't start the daemon  */
    arguments->start_daemon = 0;

    /* by default, don't stop the daemon  */
    arguments->stop_daemon = 0;

    /* by default, use 4 threads  */
    arguments->threads = 4;
}

/** This is the parser's configuration. */
static struct argp argp = {
    .options  = options,
    .parser   = parse_arg,
    .args_doc = NULL,
    .doc      = description,
};

int main(int argc, char** argv) {
    /* start with the default arguments */
    struct arguments arguments;
    set_default_params(&arguments);

    /* parse command line arguments */
    argp_parse(&argp, argc, argv, 0, 0, &arguments);

#ifdef DEBUG
    printf("Socket:   \"%s\"\n", arguments.socket);
    printf("Log:      \"%s\"\n", arguments.log);
    printf("Start:    %s\n", (arguments.start_daemon) ? "true" : "false");
    printf("Stop:     %s\n", (arguments.stop_daemon)  ? "true" : "false");
    printf("Threads:  %d\n", arguments.threads);
#endif

    /* start the daemon */
    if(arguments.start_daemon) {
        int fd = open(arguments.log, O_WRONLY | O_CREAT | O_APPEND, 0666);
        if(fd < 0) {
            perror("Fail to open log file:");
            exit(1);
        }
        dprintf(fd, "=======\n");
        dprintf(fd, "NEW RUN\n");
        dprintf(fd, "=======\n");
        start_daemon(arguments.threads, fd, arguments.socket);
        return 0;
    }

    /* stop the daemon */
    if(arguments.stop_daemon) {
        stop_daemon(arguments.socket);
        return 0;
    }

    /* normal startup */
    solve(arguments.threads, STDIN_FILENO);
    return 0;
}
