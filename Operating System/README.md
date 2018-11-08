<img align="center" src="image.png" alt="SIGKILL">

# Système d'Exploitation
Dans cette section, il vous faut écrire un programme multitâche permettant
de calculer des problèmes sur plusieurs fils d'exécution.

## Partie 1 : résoudre les problèmes (5pts)
Vous avez un nombre inconnue de problèmes à résoudre. Vous devez séparer la
résolution des problèmes sur plusieurs fils d'exécution.

* utilisez la librarie `pthread` ainsi que ces mutexes si nécessaire
* tuez tous les fils d'exécution lorsque le signal d'interruption (`SIGINT`) est reçu
* il ne doit pas y avoir de fuites de mémoires

**Vous devez remplir la fonction `solve` du fichier `solve.c`.**

La table suivante montre les arguments qui affectent cette partie.

| Argument            | Description                              |
|---------------------|------------------------------------------|
| `--threads=N`       | Spécifie le nombre de fils d'exécution   |

### Obtenir un problème
Pour obtenir un problème, il suffit d'utiliser cette fonction :
```
struct problem* get_problem();
```
Cette fonction ne renvoit jamais deux fois le même problème. S'il ne reste plus
de problème, la valeur `NO_PROBLEM_LEFT` est renvoyée. Cette fonction n'est pas
_thread-safe_. Si une erreur interne est survenue, la valeur `NULL` est
retournée.

### Résoudre un problème
Pour résoudre un problème, il suffit d'utiliser cette fonction :
```
void solve_problem(struct problem* problem);
```
Cette fonction n'est pas _thread-safe_ pour un même problème.

### Libérer la mémoire
Pour libérer la mémoire après la résolution d'un problème, utilisez :
```
void delete_problem(struct problem* problem);
```
Cette fonction n'est pas _thread-safe_ pour un même problème.

## Partie 2 : exécution en daemon (10pts)
On veut que la résolution des problèmes s'effectuent en arrière plan. Vous devez
permette à l'application de démarrer un daemon dans le système. Pour se faire :

* vous ne pouvez pas changer les handlers des signals
* vous ne pouvez pas utiliser la fonction `daemon()` de la librarie C
* utilisez `fork()` pour démarrer un nouveau processus

La table suivante montre les arguments qui affectent cette partie.

| Argument            | Description                              |
|---------------------|------------------------------------------|
| `--start`           | Démarre le daemon                        |
| `--stop`            | Arrête le daemon                         |
| `--socket=FICHIER`  | Spécifie le nom du tube nommé            |
| `--threads=N`       | Spécifie le nombre de fils d'exécution   |
| `--log=FICHIER`     | Spécifie le nom du fichier pour les logs |

### Démarrage du daemon
1. l'application est lancée avec l'argument `--start`
2. l'application crée un processus fils (le daemon)
3. l'application se termine
4. le fils crée un tube nommé
5. le fils démarre les fils d'exécution calculant les problèmes
6. le fils écoute le tube nommé avec `poll()`
7. le fils quitte s'il ne reste plus de problèmes

**Vous devez remplir la fonction `start_daemon` du fichier `solve.c`.**

### Fermature du daemon
1. l'application est lancée avec l'argument `--stop`
2. l'application ouvre le tube nommé du daemon
3. l'application envoit un message d'arrête au daemon
4. le daemon tue tous ses fils d'exécutions
5. le daemon se termine
6. l'application se termine

**Vous devez remplir la fonction `stop_daemon` du fichier `solve.c`.**
