/////////////////////////////////
// NE TOUCHEZ PAS À CE FICHIER //
/////////////////////////////////

#ifndef INCLUDE_PROBLEM_H
#define INCLUDE_PROBLEM_H

/**
 * Cette structure définit un problème.
 */
struct problem {
    /** Une chaîne de caractère qui ne vous concerne pas. */
    char* name;
    /** Un pointeur qui ne vous concerne pas. */
    void* lattice;
    /** Un chiffe qui ne vous concerne pas. */
    double resolution;
};

/**
 * Cette valeur spécifie qu'il ne reste plus de problème.
 */
extern const struct problem* NO_PROBLEM_LEFT;

/**
 * Cette fonction vous renvoit un problème à résoudre.
 *
 * @note Cette fonction n'est pas thread-safe.
 *
 * @return Un pointeur vers un problème s'il en reste.
 * @return S'il ne reste plus de problème, #NO_PROBLEM_LEFT est renvoyée.
 * @return S'il y a eu un problème, #NULL est renvoyée.
 */
struct problem* get_problem();

/**
 * Cette fonction résoue un problème.
 *
 * @note Cette fonction n'est pas thread-safe pour un même problème.
 *
 * @param problem Le problème à résoudre.
 */
void solve_problem(struct problem* problem);

/**
 * Cette fonction libère la mémoire d'un problème.
 *
 * @note Cette fonction n'est pas thread-safe pour un même problème.
 *
 * @param problem Le problème à détruire.
 */
void delete_problem(struct problem* problem);


#endif
