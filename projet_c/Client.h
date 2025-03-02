#ifndef CLIENT_H
#define CLIENT_H

class Client
{
private:
    int id_client ;
    QString nom_association ;
    QString adresse ;
    QString type_association ;
    QString nom_rep ;
    QString email;
    int id_contrat ;
    int ID_emp ;
public:
    Client(int id_client, QString nom_association, QString adresse, QString type_association,
           QString nom_rep, QString email, int id_contrat, int ID_emp);


    int getIdClient() ;
    QString getNomA() ;
    QString getAdresse() ;
    QString getTypeA() ;
    QString getNomR() ;
    QString getEmail() ;
    int getIdContrat() ;
    int getIdEmp() ;


    void setIdClient(int id_client);
    void setNomA( QString &nom_association);
    void setAdresse( QString &adresse);
    void setTypeA( QString &type_association);
    void setNomR( QString &nom_rep);
    void setEmail( QString &email);
    void setIdContrat(int id_contrat);
    void setIdEmp(int ID_emp);

};

#endif // CLIENT_H
