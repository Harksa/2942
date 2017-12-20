#include "game.h"

#include "enemy.h"
#include "constants.h"

Game::Game(QWidget *parent){
	//Intialisation de la variable qui indique si le jeu est en cours
	onGoing = false;
	
    //Création de la scène.
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,width_scene,height_scene);

    //Background.
    QBrush background(QImage(":/pictures/Images/Background/starBackground.png"));
    scene->setBackgroundBrush(background);

    //Rajout de la scène et paramétrages.
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width_scene,height_scene);

    //Rajouter les polices à la base de fonts.
    QFontDatabase::addApplicationFont(":/fonts/Fonts/venus rising rg.ttf"); // ID : 0

    //Musique de background.
    QUrl path("qrc:/musics/Musics/level1.mp3");

    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(path);
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer * music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
	
	//Creation des highscores
	highscores = new HighScores();
	scene->addItem(highscores);

    //Placer le jeu au milieu de l'écran.
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;
    this->move(x, y);

	
	
    show();
	
	//QGraphicsTextItem*  playButton = add_menu("Play", scene->width() * 2 / 5, scene->height() * 2 / 6 , 20);
	
	//QGraphicsTextItem*  highscoresbutton = add_menu("HighScores", scene->width() * 2 / 5, scene->height() * 4 / 6 , 20);
	
	launch_game();

    Q_UNUSED(parent)
}

void Game::mousePressEvent(QMouseEvent *event) {
    player->setFocus();

    Q_UNUSED(event);
}

void Game::launch_game(/*paramètres de niveau*/)
{
	onGoing = true; 
	
	//Création du joueur.
    player = new Player();
    scene->addItem(player);

    //Focus sur le joueur.
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Création du score.
    score = new Score();
    scene->addItem(score);

    //Création de la vie.
    health = new HealthUI();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    connect(player, SIGNAL(healthDecreased(int)), health, SLOT(healthChanged(int)));

    //Spawner d'ennemis.
    spawner = new Spawner();

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),spawner,SLOT(spawn()));
    timer->start(2000);
}

void Game::game_over()
{
	onGoing = false;
	
	//Message Game over
    add_menu("Game Over", scene->width() * 1 / 10 ,  scene->height() / 3 , 30);
	
	//Calcul et affichage du TOP 10
	highscores->checkHighScores(score->getScore());
    highscores->showHighScores();
	
	//Bouton Rejouer
	QGraphicsTextItem*  rejouer = add_menu("Play Again", scene->width() * 3 / 5, scene->height() * 5 / 6 , 20);
	//rejouer->mousePressEvent(QMouseEvent *event){ add_menu("Patatatata", scene->width() * 3 / 5, scene->height() * 5 / 6 , 20);}
	
	//Bouton  Menu
    QGraphicsTextItem* menu = add_menu("Menu", scene->width() * 0.5 / 5 , scene->height() * 5 / 6, 20);
}

QGraphicsTextItem* Game::add_menu(QString texte, int posX, int posY, int fontHeight)
{
	QGraphicsTextItem * menu = new QGraphicsTextItem(texte);
    menu->setDefaultTextColor(Qt::white);
    QString font = QFontDatabase::applicationFontFamilies(0).at(0);
    menu->setFont(QFont(font, fontHeight)); 
	scene->addItem(menu);
	menu->setPos(posX, posY);
	return menu;
}



bool Game::getOnGoing()
{
	return onGoing;
}
