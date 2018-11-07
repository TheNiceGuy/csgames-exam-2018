/////////////////////////////////
// NE TOUCHEZ PAS À CE FICHIER //
/////////////////////////////////

#ifndef SOLVE_H
#define SOLVE_H

/**
 * Cette fonction effectue la résolution des problèmes.
 *
 * @param threads Le nombre de fils d'exécution.
 * @param log     Un descripteur de fichier pour logger de l'information.
 */
void solve(int threads, int log);

/**
 * Cette fonction démarre le daemon.
 *
 * @param threads Le nombre de fils d'exécution.
 * @param log     Un descripteur de fichier pour logger de l'information.
 * @param socket  Le nom du tube nommé pour communiquer.
 */
void start_daemon(int threads, int log, char* socket);

/**
 * Cette fonction arrête le daemon.
 *
 * @param socket  Le nom du tube nommé pour communiquer.
 */
void stop_daemon(char* socket);

#endif
