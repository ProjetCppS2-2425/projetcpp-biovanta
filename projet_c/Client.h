#ifndef CLIENT_H
#define CLIENT_H

class Client
{
private:
    int id_c ;
    QString nomA ;
    QString adresse ;
    QString typeA ;
    QString nomR ;
    QString email;
    int id_contrat ;
    int id_emp ;
public:
    Client(int id_c, QString nomA, QString adresse, QString typeA,
           QString nomR, QString email, int id_contrat, int id_emp);


    int getIdClient() ;
    QString getNomA() ;
    QString getAdresse() ;
    QString getTypeA() ;
    QString getNomR() ;
    QString getEmail() ;
    int getIdContrat() ;
    int getIdEmp() ;


    void setIdClient(int id_c);
    void setNomA( QString &nomA);
    void setAdresse( QString &adresse);
    void setTypeA( QString &typeA);
    void setNomR( QString &nomR);
    void setEmail( QString &email);
    void setIdContrat(int id_contrat);
    void setIdEmp(int id_emp);
    bool ajouter();

};

#endif // CLIENT_H
