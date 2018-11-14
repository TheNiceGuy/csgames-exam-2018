#ifndef MD5_INCLUDE_H
#define MD5_INCLUDE_H

#define TRUE  1
#define FALSE 0

#define size_t unsigned int
#define uint8_t unsigned char
#define uint32_t unsigned int
#define uint64_t unsigned long long

typedef struct md5 {
    /*
     * Contient le prochain bloc de 512 bits à transformer.
     */
    uint8_t buffer[64];
    /**
     * Contient les registres de la signature.
     */
    uint32_t digest[4];
    /*
     * Contient la position du buffer afin de rajouter des bits.
     */
    uint64_t pos;
    /**
     * Contient la taille total du message.
     */
    uint64_t len;
} md5_t;

/**
 * Cette fonction initialise les registres de l'algorithme et de la structure ::md5.
 *
 * @param md5 Un pointeur vers une structure ::md5.
 */
void md5_init(struct md5* md5);

/**
 * Cette fonction ajoute des bits dans le buffer interne de la structure ::md5. Si le
 * buffer atteint une taille de 512 bits, alors une transformation md5 est effectuée avec
 * la fonction md5_transform().
 *
 * @param md5  Un pointeur vers une structure ::md5.
 * @param data Un pointeur vers les bits à ajouter.
 * @param len  La taille de bits à ajouter.
 */
void md5_update(struct md5* md5, uint8_t* data, size_t len);

/**
 * Cette fonction finalise la signature de la structure ::md5 calculée. Elle devrait être
 * appelée à la fin et une seule fois.
 *
 * @param md5  Un pointeur vers une structure ::md5.
 */
void md5_finish(struct md5* md5);

/**
 * Cette fonction effectue une transformation md5 sur les registres r à l'aide du bloc
 * de 512 bits x.
 *
 * @param r Un pointeur vers les 4 registres.
 * @param x Un pointeur vers un bloc de 512 bits.
 */
void md5_transform(uint32_t* r, uint32_t* x);

#endif
