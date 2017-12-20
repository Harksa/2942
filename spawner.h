#ifndef SPAWNER_H
#define SPAWNER_H

#include <QObject>

#include "enemy.h"

/**
 * @brief Type d'ennemi possible.
 */
enum TypeEnemy {
    GREEN,
    RED
};

/**
 * @brief structure d'une vague d'ennemis.
 */
struct Wave {
    /**
     * @brief type Le type d'ennemi apparaissant dans cette vague.
     */
    TypeEnemy type;

    /**
     * @brief quantity La quantité d'ennemi pour cette vague.
     */
    int quantity;

    /**
     * @brief position La position de départ de la vague.
     */
    int position;

    /**
     * @brief Wave Constructeur pour la structure.
     * @param t le type d'ennemi
     * @param q La quantité
     * @param pos La position
     */
    Wave(TypeEnemy t, int q, int pos) {
       type = t;
       quantity = q;
       position = pos;
    }
};

/**
 * @brief Classe permettant de spawner des ennemis, vagues après vagues.
 * Les vagues sont actuellements lus à partir d'un fichier txt rennomé en .spwn.
 * Le fichier texte doit contenir la structure suivante :
 * Type, Quantité, Position
 * Et ce pour chaque ligne (et doit finir par une ligne vide).
 */
class Spawner : public QObject {
    Q_OBJECT
public:
    /**
     * @brief Spawner Le constructeur pour le Spawner.
     */
    explicit Spawner(QObject *parent = nullptr);

    /**
     * @brief startSpawning La fonction permettant de démarrer les vagues ennemis.
     */
    void startSpawning();
private:
    /**
     * @brief waves La liste des vagues.
     */
    QList<Wave> waves;

    /**
     * @brief timerSpawnWave Le timer pour la prochaine vague.
     */
    QTimer * timerSpawnWave;

    /**
     * @brief timerSpawnEnemies Le timer pour le prochain ennemi de la vague courrante.
     */
    QTimer * timerSpawnEnemies;

    /**
     * @brief delayBeforeNewVague Le temps avant l'apparition d'une nouvelle vague.
     */
    int delayBeforeNewVague = 3000;

    /**
     * @brief delayBeforeSpawn Le temps avant l'apparition d'un nouveau vaisseau.
     */
    int delayBeforeSpawn = 500;         //Optimal pour la taille actuelle des vaisseaux

    /**
     * @brief currentWave La position dans la liste waves de la vague en court.
     */
    int currentWave;

    /**
     * @brief enemy_count Le compteur d'ennemi de la vague en court.
     */
    int enemy_count;

    /**
     * @brief chooseEnemyFromType Permet de choisir l'Enemy en fonction de son type.
     * @param type Le type d'ennemi.
     * @return Un Enemy.
     */
    Enemy *chooseEnemyFromType(TypeEnemy type);

private slots:
    /**
     * @brief spawnWave Permet de faire apparaitre une vague.
     */
    void spawnWave();

    /**
     * @brief spawnEnemy Permet de faire apparaite un ennemi.
     */
    void spawnEnemy();
};

#endif // SPAWNER_H
