/**
 * \file	noteversion.h
 * \brief	Définition de la classe NoteVersion
 * \details La classe NoteVersion est une amie de la classe Note, une version de note peut être un article, un fichier image, un fichier vidéo, un fichier son ou une tâche.
 */

#ifndef NOTEVERSION_H
#define NOTEVERSION_H

#include <iostream>
#include <QApplication>
#include <QString>
#include <QFileDialog>
#include <vector>
#include<QDebug>
#include "date.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>
#include <QXmlStreamWriter>


/**
* \class NoteVersion noteversion.h
* \details Classe amie de Note
*/
class FormVersion;
class NoteVersion{
    friend class Note;

protected:
    unsigned int idVersion;
    Date dateEdit;

private:
    QString title;
    //template<typename T> static DerivedRegister<T> reg;

    /**
    * \brief		Méthode pour sauvegarder une version d'une note
    * \details  Elle permet de sauvegarder les version d'une note dans un fichier xml lors d'un enregistrement
    * \param    stream  Fichier QXmlStreamWriter qui permet de sauver les versions d'une note
    */
    void saveNoteVersion(QXmlStreamWriter* stream) const;

    /**
    * \brief		Méthode pour charger une version d'une note
    * \details  Elle permet de charger les versions d'une note à partir d'un fichier xml
    * \param    &xml  Référence vers le fichier xml d'où on va charger les versions d'une note
    */
    void loadNoteVersion(QXmlStreamReader& stream);

    /**
    * \brief		Méthode pour sauvegarder une version d'un type de note
    * \details  Elle permet de sauvegarder les version d'un type de note dans un fichier xml lors d'un enregistrement
    * \param    stream  Fichier QXmlStreamWriter qui permet de sauver les versions d'un type de note
    */
    virtual void saveNoteVersionType(QXmlStreamWriter& stream) const=0;

    /**
    * \brief		Méthode pour charger une version d'un type de note
    * \details  Elle permet de charger les versions d'un type de note à partir d'un fichier xml
    * \param    &xml  Référence vers le fichier xml d'où on va charger les versions d'un type de note
    */
    virtual void loadNoteVersionType(QXmlStreamReader& stream)=0;


public :

    /**
    * \brief		Constructeur de la classe NoteVersion
    * \param    v  Id de la version
    * \param    t  Titre de la version
    */
    NoteVersion(unsigned int v, const QString& t);

    /**
    * \brief		Accesseur pour obtenir le titre d'une version d'une note
    */
    const QString& getTitle() const ;

    /**
    * \brief		Méthode pour attribuer un titre à une version d'une note
    * \param    str   Titre d'une version
    */
    void setTitle(const QString& str);

    /**
    * \brief		Accesseur pour obtenir la date d'édition d'une version d'une note
    */
    const Date& getDateEdit() const;

    /**
    * \brief		Méthode pour attribuer une date d'édition à une version d'une note
    * \param    d   Date d'édition d'une version
    */
    void setDateEdit(const Date& d);

    /**
    * \brief		Accesseur pour obtenir l'id d'une version d'une note
    */
    unsigned int getIdVersion() const;

    /**
    * \brief  Destructeur d'une version d'une note
    * \details  Il est virtuel
    */
    virtual ~NoteVersion();

    /**
    * \brief Méthode clone
    * \return Un pointeur de NoteVersion sur le clone de la version grâce à l'id
    * \param  id  L'id de la version que l'on souhaite cloner
    */
    virtual NoteVersion* clone(unsigned int id) const=0;

    virtual QString type() const =0;

    virtual FormVersion* formVersion()=0;

/*
A FAIRE :

 changeVersion : restaurer une ancienne version en tant que version actuelle (design pattern : memento?)

*/

};

/*********************************NoteVersionFactory***********************/
/**
* \brief Utilisée pour les méthodes de chargement
*/
template<typename T> NoteVersion * createT() { return new T;}

/**
* \class NoteVersionFactory noteversion.h
*/
class NoteVersionFactory {
public:
    typedef std::map<QString, NoteVersion*(*)()> map_type;

private:
    static map_type * map;
public:
    static map_type * getMap();
    static NoteVersion * createInstance(const QString & s) ;

};

template<typename T>
struct DerivedRegister :public NoteVersionFactory {
    DerivedRegister(QString const& s) {
        getMap()->insert(std::make_pair(s, &createT<T>));
    }
};


/********************************** Article ****************************/

/**
* \class Article noteversion.h
*/
class Article : public NoteVersion {
    friend class Note;

    QString text;
    static DerivedRegister<Article> reg;

    /**
    * \brief		Méthode pour sauvegarder une version d'un type de note
    * \details  Elle permet de sauvegarder les version d'un type de note dans un fichier xml lors d'un enregistrement
    * \param    stream  Fichier QXmlStreamWriter qui permet de sauver les versions d'un type de note
    */
    void saveNoteVersionType(QXmlStreamWriter& stream) const;

    /**
    * \brief		Méthode pour charger une version d'un type de note
    * \details  Elle permet de charger les versions d'un type de note à partir d'un fichier xml
    * \param    &xml  Référence vers le fichier xml d'où on va charger les versions d'un type de note
    */
    void loadNoteVersionType(QXmlStreamReader& stream);

public :

    /**
    * \brief		Constructeur de la classe Article
    * \param    te  Texte de l'article
    * \param    t  Titre de l'article (utilisé par le constructeur de NoteVersion)
    */
    Article (const QString& t=QString(), const QString& te=QString());

    /**
    * \brief		Accesseur pour obtenir le texte d'un article
    */
    const QString& getText() const;

    /**
    * \brief		Méthode pour attribuer un texte à un article
    * \param    str   Texte d'une version
    */
    void setText(const QString& str);

    /**
    * \brief Méthode clone
    * \return Un pointeur de Article sur le clone de l'article grâce à l'id
    * \param  id  L'id de l'article que l'on souhaite cloner
    */
    Article* clone(unsigned int id) const;
    QString type() const;
    FormVersion* formVersion();
};


/********************************** Task ****************************/

/**
* \class Task noteversion.h
*/
class Task : public NoteVersion {
    friend class Note;

    QString action;
    unsigned int priority;
    Date deadline;
    enum Status {waiting, ended, in_progress};
    Status status;
    static DerivedRegister<Task> reg;

    /**
    * \brief		Méthode pour sauvegarder une version d'un type de note
    * \details  Elle permet de sauvegarder les version d'un type de note dans un fichier xml lors d'un enregistrement
    * \param    stream  Fichier QXmlStreamWriter qui permet de sauver les versions d'un type de note
    */
    void saveNoteVersionType(QXmlStreamWriter& stream) const;

    /**
    * \brief		Méthode pour charger une version d'un type de note
    * \details  Elle permet de charger les versions d'un type de note à partir d'un fichier xml
    * \param    &xml  Référence vers le fichier xml d'où on va charger les versions d'un type de note
    */
    void loadNoteVersionType(QXmlStreamReader& stream);

public :

    /**
    * \brief		Constructeur de la classe Tâche
    * \param    t  Titre de la tâche (utilisé par le constructeur de NoteVersion)
    * \param    a  Action de la tâche
    * \param    p  Prioritée de la tâche
    * \param    d  Date de la tâche
    * \param    s  Statut de la tâche
    */
    Task (const QString& t=QString(),const QString& a=QString(), unsigned int p=0, const Date d=Date(1,1,2100), const Status s=Status());

    /**
    * \brief		Accesseur pour obtenir l'action d'une tâche
    */
    const QString& getAction() const ;

    /**
    * \brief		Accesseur pour obtenir la prioritée d'une tâche
    */
    unsigned int getPriority() const ;

    /**
    * \brief		Accesseur pour obtenir la date deadline d'une tâche
    */
    const Date& getDeadline() const ;

    /**
    * \brief		Accesseur pour obtenir le statut d'une tâche
    */
    const Status& getStatus() const ;

    /**
    * \brief Méthode clone
    * \return Un pointeur de task sur le clone de la tâche grâce à l'id
    * \param  id  L'id de la tâche que l'on souhaite cloner
    */
    Task* clone(unsigned int id) const;
    QString type() const ;
    FormVersion* formVersion();

};
/********************************** Image ****************************/

/**
* \class Image noteversion.h
*/
class Image : public NoteVersion {
    friend class Note;

    QString description;
    QString file;
    static DerivedRegister<Image> reg;

    /**
    * \brief		Méthode pour sauvegarder une version d'un type de note
    * \details  Elle permet de sauvegarder les version d'un type de note dans un fichier xml lors d'un enregistrement
    * \param    stream  Fichier QXmlStreamWriter qui permet de sauver les versions d'un type de note
    */
    void saveNoteVersionType(QXmlStreamWriter& stream) const;

    /**
    * \brief		Méthode pour charger une version d'un type de note
    * \details  Elle permet de charger les versions d'un type de note à partir d'un fichier xml
    * \param    &xml  Référence vers le fichier xml d'où on va charger les versions d'un type de note
    */
    void loadNoteVersionType(QXmlStreamReader& stream);


public :
    /**
    * \brief		Constructeur de la classe Image
    * \param    t  Titre de l'Image (utilisé par le constructeur de NoteVersion)
    * \param    d  Description de l'Image
    * \param    f  Fichier de l'Image
    */
    Image(const QString& t=QString(), const QString& d=QString(), const QString& f=QString());

    /**
    * \brief		Accesseur pour obtenir la description d'une Image
    */
    const QString& getDescription() const;

    /**
    * \brief		Accesseur pour obtenir le fichier d'une Image
    */
    const QString& getFile() const ;
    void setFile(const QString& str)  ;


    /**
    * \brief Méthode clone
    * \return Un pointeur de Image sur le clone de l'image grâce à l'id
    * \param  id  L'id de l'image que l'on souhaite cloner
    */
    Image* clone(unsigned int id) const;
    QString type() const ;
    FormVersion* formVersion();
};


/********************************** Audio ****************************/

/**
* \class Audio noteversion.h
*/
class Audio : public NoteVersion {
    friend class Note;

    QString description;
    QString file;
    static DerivedRegister<Audio> reg;

    /**
    * \brief		Méthode pour sauvegarder une version d'un type de note
    * \details  Elle permet de sauvegarder les version d'un type de note dans un fichier xml lors d'un enregistrement
    * \param    stream  Fichier QXmlStreamWriter qui permet de sauver les versions d'un type de note
    */
    void saveNoteVersionType(QXmlStreamWriter& stream) const;

    /**
    * \brief		Méthode pour charger une version d'un type de note
    * \details  Elle permet de charger les versions d'un type de note à partir d'un fichier xml
    * \param    &xml  Référence vers le fichier xml d'où on va charger les versions d'un type de note
    */
    void loadNoteVersionType(QXmlStreamReader& stream);

public :

    /**
    * \brief		Constructeur de la classe Audio
    * \param    t  Titre d'une note Audio (utilisé par le constructeur de NoteVersion)
    * \param    d  Description d'une note Audio
    * \param    f  Fichier d'une note Audio
    */
    Audio (const QString& t, const QString& d, const QString& f);

    /**
    * \brief		Accesseur pour obtenir la description d'une note Audio
    */
    const QString& getDescription() const;

    /**
    * \brief		Accesseur pour obtenir le fichier d'une note Audio
    */
    const QString& getFile() const;

    /**
    * \brief Méthode clone
    * \return Un pointeur de Audio sur le clone de la note Audio grâce à l'id
    * \param  id  L'id de la note Audio que l'on souhaite cloner
    */
    Audio* clone(unsigned int id) const;
    QString type() const;
    FormVersion* formVersion();
};


/********************************** Video ****************************/

/**
* \class Video noteversion.h
*/
class Video : public NoteVersion {
    friend class Note;

    QString description;
    QString file;
    static DerivedRegister<Video> reg;

    /**
    * \brief		Méthode pour sauvegarder une version d'un type de note
    * \details  Elle permet de sauvegarder les version d'un type de note dans un fichier xml lors d'un enregistrement
    * \param    stream  Fichier QXmlStreamWriter qui permet de sauver les versions d'un type de note
    */
    void saveNoteVersionType(QXmlStreamWriter& stream) const;

    /**
    * \brief		Méthode pour charger une version d'un type de note
    * \details  Elle permet de charger les versions d'un type de note à partir d'un fichier xml
    * \param    &xml  Référence vers le fichier xml d'où on va charger les versions d'un type de note
    */
    void loadNoteVersionType(QXmlStreamReader& stream);

public :

    /**
    * \brief		Constructeur de la classe Video
    * \param    t  Titre d'une note Video (utilisé par le constructeur de NoteVersion)
    * \param    d  Description d'une note Video
    * \param    f  Fichier d'une note video
    */
    Video (const QString& t, const QString& d, const QString& f);

    /**
    * \brief		Accesseur pour obtenir la description d'une note Video
    */
    const QString& getDescription() const;

    /**
    * \brief  Accesseur pour obtenir le fichier d'une note Video
    */
    const QString& getFile() const;

    /**
    * \brief Méthode clone
    * \return Un pointeur de Video sur le clone de la note Video grâce à l'id
    * \param  id  L'id de la note Video que l'on souhaite cloner
    */
    Video* clone(unsigned int id) const;
    QString type() const;
    FormVersion* formVersion();
};


/*************************INTERFACE NOTEVERSION************************/

/**
* \class FormVersion noteversion.h
*/
class FormVersion : public QWidget{
        Q_OBJECT
public:
    FormVersion(QWidget *parent = 0);
    virtual void saveVersion(NoteVersion*)=0;
    virtual ~FormVersion()=0;
};

/**
* \class FormArticle noteversion.h
*/
class FormArticle : public FormVersion{
    Article *article;
    QLabel *textLabel;
    QTextEdit *text;
    QHBoxLayout *textHbox;
public:
    FormArticle(Article *a, QWidget *parent = 0);
    void saveVersion(NoteVersion*ver);
    ~FormArticle();
};

/**
* \class FormImage noteversion.h
*/
class FormImage : public FormVersion{
    Q_OBJECT

    QPushButton *import;
    Image *image;
    QLabel *imageLabel;
    QHBoxLayout *imageHbox;

private slots:
    void importImage();

public:
    FormImage(Image* a, QWidget *parent = 0);
    void printImage();
    void saveVersion(NoteVersion*){};
    ~FormImage();

};
#endif // NOTEVERSION_H
