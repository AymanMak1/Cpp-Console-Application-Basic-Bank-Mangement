#include<iostream>
#include<fstream>
#include<string>
//------ la bibliotheque ctime on va l'utiliser pour afficher la date d'ouverture de compte----------------
#include<ctime>

using namespace std;

//---------------declaration des structures--------------

struct client
{
	int id_client;
	char prenom[20];
	char nom[20];
	char profession[20];
	char num_tel[20];
	char cin[20];
};

struct compte
{
	int id_compte;
	int id_client;
	float solde;
	time_t date_ouv;
};

struct client c1;
struct compte cm;
char c;
int choix,choix2;
//**********************************declaration des fonctions********************************
void menu_general (char c,int choix,char choix2);
int recherche (int numrech);
//int recherche2 (int numrech);

//------------Fonctions de Gestion des clients-------------
void menu_general (char c,int choix,char choix2);
int recherche (int numrech);
void creerClient();
void chercher();
void supprimer();
void ModifierClient();
void AfficherTout();


//---------------Fonctions de Gestion des comptes--------------
void CreerCompte();
int checksolde();
void fermerCompte();

//--------------------Fonction de Gestion des operations---------------------------
void retirer();
void verser();
void ajouterMontant();

//-----------------Fonction de le menu general ou des choix--------------------------

void menu_general (char c,int choix,char choix2)
{
	switch(choix)
	{
		case 1:
			cout<<"\t\t\t\t\t a:Ajouter un client."<<endl<<"\t\t\t\t\t b:Modifier ses informations"<<endl<<"\t\t\t\t\t c:Le supprimer."<<endl;
			cout<<"\t\t\t\t\t d:chercher un certain client par son Identificateur."<<endl<<"\t\t\t\t\t e:Afficher Tous Les clients"<<endl<<"\t\t\t\t\t f:Quitter"<<endl;
			cin>>choix2;
				
				switch(choix2)
				{
					case'a':
							cout<<"taper les coordonees de client:"<<endl;
							creerClient();
					break;					
					
					case'b':
							ModifierClient();
					break;
		
					case'c':
							supprimer();
					break;	
		
					case'd':
							chercher();
					break;
					
					case'e':
							AfficherTout();	
					break;
						
					case'f':
							cout<<"Vous etes sure de quitter votre operation o/n ??"<<endl;
							cin>>c;
							if(c=='o')
							{	
								cout<<"A bientot !!"<<endl;
							}
							if(c=='n')
							{
							system("cls");
							cout<<"-----------------------------------------Bienvenue dans notre service Banquaire------------------------------------------------"<<endl;
							cout<<"\t\t\t\t\t 1:Gestion des clients."<<endl<<"\t\t\t\t\t 2:Gestion des comptes"<<endl<<"\t\t\t\t\t 3:Gestion des operations."<<endl<<"\t\t\t\t\t 4:Quitter"<<endl;
							cin>>choix;
							menu_general(c,choix,choix2);
							}
					break;					
				}
		break;
		
		case 2:
			cout<<"\t\t\t\t\t a:Creer un compte pour un client donne avec son Identificateur,."<<endl<<"\t\t\t\t\t b:Consulter son solde."<<endl<<"\t\t\t\t\t c:Quitter."<<endl;
			cin>>choix2;
			
				switch(choix2)
				{
					case'a':
							CreerCompte();
					break;					
					
					case'b':
							checksolde();
					break;
		
					case'c':
							cout<<"Vous etes sure de quitter votre operation o/n ??"<<endl;
							cin>>c;
							if(c=='o')
							{	
								cout<<"A bientot !!"<<endl;
							}
							if(c=='n')
							{
								system("cls");
							cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Bienvenue dans notre service Banquaire<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,<<"<<endl;
							cout<<"\t\t\t\t\t 1:Gestion des clients."<<endl<<"\t\t\t\t\t 2:Gestion des comptes"<<endl<<"\t\t\t\t\t 3:Gestion des operations."<<endl<<"\t\t\t\t\t 4:Quitter"<<endl;
							cin>>choix;
							menu_general(c,choix,choix2);
							}
					break;
									
				}
		break;
		
		
		case 3:
			cout<<"\t\t\t\t\t a:Choisir un montant a retirer"<<endl<<"\t\t\t\t\t b:Choisir un montant a verser."<<endl<<"\t\t\t\t\t c:Choisir un montant a ajouter "<<endl<<"\t\t\t\t\t d:Quitter"<<endl;
			cin>>choix2;
		
				switch(choix2)
				{
					case'a':
						retirer();
					break;					
					
					case'b':
						verser();	
					break;
					
					case'c':
						ajouterMontant();
					break;
					
					case 'd':
							cout<<"Vous etes sure de quitter votre operation o/n ??"<<endl;
							cin>>c;
							if(c=='o')
							{	
								cout<<"A bientot !!"<<endl;
							}
							if(c=='n')
							{
							system("cls");
							cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Bienvenue dans notre service Banquaire<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
							cout<<"\t\t\t\t\t 1:Gestion des clients."<<endl<<"\t\t\t\t\t 2:Gestion des comptes"<<endl<<"\t\t\t\t\t 3:Gestion des operations."<<endl<<"t\t\t\t\t 4:Quitter"<<endl;
							cin>>choix;
							menu_general(c,choix,choix2);
							}					
					break;	
				}		
		break;
		
		case 4 :
				cout<<"Vous etes sure de quitter notre service ??"<<endl<<"a:Oui"<<endl<<"b:Non"<<endl;
				cin>>choix2;
				switch(choix2)
				{
					case'a':
						cout<<"A bientot!!"<<endl;
					break;					
					
					case'b':
							system("cls");
							cout<<"--------------------------------Bienvenue dans notre service Bancaire------------------------------------------------"<<endl;
							cout<<"\t\t\t\t\t 1:Gestion des clients."<<endl<<"\t\t\t\t\t 2:Gestion des comptes"<<endl<<"\t\t\t\t\t3:Gestion des operations."<<endl<<"\t\t\t\t\t 4:Quitter"<<endl;
							cin>>choix;
							menu_general(c,choix,choix2);					
					break;		
				}				
		break;
			
		default:cout<<"Please Taper 1 choix parmis les 4 choix!!"<<endl;				
				cout<<"\t\t\t\t\t 1:Gestion des clients."<<endl<<"\t\t\t\t\t 2:Gestion des comptes"<<endl<<"\t\t\t\t\t 3:Gestion des operations."<<endl<<"\t\t\t\t\t 4:Quitter"<<endl;
				cin>>choix;
				menu_general(c,choix,choix2);	
		break;	
	}
}
//--------------fonction rechercher est pour sois sure est ce que le client il existe ou pas et aider sure la supression d'un client et plusieur fonctions---------------------------

int recherche (int numrech)
{
 	ifstream fichier (" tp6projet.txt", ios::in );
	if(fichier)
	{   
		do
		{
			fichier>>c1.id_client>>c1.nom>>c1.prenom>>c1.cin>>c1.profession>>c1.num_tel;
			if (c1.id_client==numrech)
			{
				fichier.close();
				return 1;
			}
		}while(!fichier.eof());
		
		fichier.close();
		return -1;		
	}
}
 //--------------fonction creer un nouveau client---------------------
void creerClient()
{
	int id;
	char o,c;
	ofstream fichier (" tp6projet.txt", ios::out | ios::app );
	if(fichier)
	{
		//---------------- cette partie avant les coordonnees de client est en relation avec la fonction recherche------------------
		cout<<"entrez l'id' de nouveau client"<<endl;
		cin>>id;
		while(recherche(id)==1)
		{
			cout<<"Ce numero deja existe"<<endl;
			cout<<"taper l'id' de nouveau client"<<endl;
			cin>>id;			
		}
		//----------------------------Coordonnees d'un nouveau client------------------------
		c1.id_client=id;	
		cout<<"Son Nom"<<endl;
		cin>>c1.nom;
		cout<<"Son Prenom"<<endl;
		cin>>c1.prenom;
		cout<<"Son CIN"<<endl;
		cin>>c1.cin;
		cout<<"Sa Profession"<<endl;
		cin>>c1.profession;
		cout<<"Son Numero De Telephone"<<endl;
		cin>>c1.num_tel;
		fichier<<c1.id_client<<" "<<c1.nom<<" "<<c1.prenom<<" "<<c1.cin<<" "<<c1.profession<<" "<<c1.num_tel<<endl;
		cout<<"Vous voulez ajouter un autre client o/n ??"<<endl;
		cin>>o;
		if(o=='o')
		{
			creerClient();
		}
		else
		{
			
			cout<<"Vous etes sure de quitter notre service o/n ??"<<endl;
			cin>>c;
			if(c=='o')
			{	
				cout<<"A bientot !!"<<endl;
			}
			if(c=='n')
			{
				system("cls");
				cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Bienvenue dans notre service Banquaire<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
				cout<<"\t\t\t\t\t 1:Gestion des clients."<<endl<<"\t\t\t\t\t 2:Gestion des comptes"<<endl<<"\t\t\t\t\t 3:Gestion des operations."<<endl<<"\t\t\t\t\t 4:Quitter"<<endl;
				cin>>choix;
				menu_general(c,choix,choix2);
		}
		fichier.close();	
		}
	}
}
//-------------------Cette fonction pour chercher un certain client par son Identificateur-----------------------------

void chercher()
{
	int numR;
	cout<<"Taper l'identificateur de client a rechercher"<<endl;
	cin>>numR;
	ifstream fichier (" tp6projet.txt", ios::in );
	if(fichier)
	{ 
	 do
	 {  
	 	fichier>>c1.id_client>>c1.nom>>c1.prenom>>c1.cin>>c1.profession>>c1.num_tel;
		if(recherche(numR)==1)
		{
			if(c1.id_client==numR)
			{
				cout<<"Son Nom:"<<c1.nom<<endl;
				cout<<"Son Prenom:"<<c1.prenom<<endl;
				cout<<"Son CIN:"<<c1.cin<<endl;
				cout<<"Sa Profession:"<<c1.profession<<endl;
				cout<<"Son Numero De Telephone:"<<c1.num_tel<<endl;	
			}
			cout<<"Vous voulez Chercher un autre client o:OUI n:NON ??"<<endl;
			cin>>c;
			switch(c)
			{
				case'o': chercher(); break;
				case'n': cout<<"A bientot !!" <<endl; break;
			}
			
			break;
		}
		else
		{
			cout<<"Cet id n'existe pas !!"<<endl;
			break;
		}
	  }while(!fichier.eof());
		fichier.close();
	}
}

void supprimer()
{
	int id_c;
		cout<<"taper l'id' de client a supprimer"<<endl;
		cin>>id_c;
		if(recherche(id_c)==1)
		{
			cout<<"Vous etes sure de supprimer!!'"<<endl<<"o:Oui"<<endl<<"n:non"<<endl;
			cin>>c;
			if(c=='o')
			{
				ifstream fichier (" tp6projet.txt", ios::in );
				ofstream tempsup (" tempS.txt", ios::out | ios::trunc );
					do
					{
						fichier>>c1.id_client>>c1.nom>>c1.prenom>>c1.cin>>c1.profession>>c1.num_tel;
						if(c1.id_client!=id_c)
						{
							tempsup<<c1.id_client<<endl<<c1.nom<<endl<<c1.prenom<<endl<<c1.cin<<endl<<c1.profession<<endl<<c1.num_tel<<endl;
						}
						
					}while(!fichier.eof());
					tempsup.close();
					fichier.close();
					remove("tp6projet.txt");
					rename("tempS.txt","tp6projet.txt");
					cout<<"Suppression a ete effectue avec success !!"<<endl;
			}
			else
			{
				cout<<"La Supression a ete annulee !!"<<endl;
				menu_general(c,choix,choix2);
			}		
		}
		else
		{
			cout<<"Cet id n'existe pas !!"<<endl;
		}
}
void ModifierClient()
{
	int idc;
	char c;
	string line;
	cout<<"Taper l'id de client a modifier"<<endl;
	cin>>idc;
	ofstream tempmodif("temp.txt",ios::out | ios::trunc);
	ifstream fichier (" tp6projet.txt", ios::in );
	if(fichier)
	{   
		if(recherche(idc)==1)
		{
					cout<<"Vous etes sure de modifier ce client"<<endl<<"o:Oui"<<endl<<"n:Non"<<endl;
			cin>>c;
			if(c=='o')
			{
				while(!fichier.eof())
				{	
					fichier>>c1.id_client>>c1.nom>>c1.prenom>>c1.cin>>c1.profession>>c1.num_tel;
					if(c1.id_client!=idc)
					{
						tempmodif<<c1.id_client<<"  "<<c1.nom<<"  "<<c1.prenom<<"  "<<c1.cin<<"  "<<c1.profession<<"  "<<c1.num_tel<<endl;	
					}
					else
					{
						if(c1.id_client==idc)
						{
							cout<<"Maintenant vous pouvez taper les nouvelles coordonnes de ce client."<<endl;
							c1.id_client=idc;	
							cout<<"Son Nouveau Nom"<<endl;
							cin>>c1.nom;
							cout<<"Son Nouveau Prenom"<<endl;
							cin>>c1.prenom;
							cout<<"Son Nouveau CIN"<<endl;
							cin>>c1.cin;
							cout<<"Sa Nouvelle Profession"<<endl;
							cin>>c1.profession;
							cout<<"Son Nouveau Numero De Telephone"<<endl;
							cin>>c1.num_tel;
							tempmodif<<c1.id_client<<"  "<<c1.nom<<"  "<<c1.prenom<<"  "<<c1.cin<<"  "<<c1.profession<<"  "<<c1.num_tel<<endl;							
						}
					}
				}
				tempmodif.close();
				fichier.close();
				remove("tp6projet.txt");
				fichier.close();
				//system("del tp6projet.txt");
				rename("temp.txt","tp6pnouvprojet.txt");
				cout<<"La modification a ete bien effectue"<<endl;
			}
			if(c=='n')
			{
				cout<<"la modification a ete annulee !!"<<endl;
			}
		}
		else
		{
			cout<<"Cet id n'existe pas !!"<<endl;
			ModifierClient();
		}
	}

}
//---------------------------------cette fonction vous permet d'afficher
void AfficherTout()
{
	string line;
	ifstream fichier (" tp6projet.txt", ios::in );
	if(fichier)
	{   
		cout<<"Voici le menu de tous les Client de notre service bancaire"<<endl;
		cout<<"ID  "<<"Nom "<<"   Prenom"<<"   CIN "<<" Profession "<<"Num_Tel     "<<endl;
		while(getline(fichier,line))
		{
			cout<<line<<endl;
		}
			cout<<"Voulez Vous faire une autre operation o/n ??"<<endl;
			cin>>c;
			if(c=='n')
			{	
				cout<<"A bientot !!"<<endl;
			}
			if(c=='o')
			{
				system("cls");
				cout<<"-----------------------------------------Bienvenue dans notre service Bancaire------------------------------------------------"<<endl;
				cout<<"\t\t\t\t\t 1:Gestion des clients."<<endl<<"\t\t\t\t\t 2:Gestion des comptes"<<endl<<"\t\t\t\t\t 3:Gestion des operations."<<endl<<"\t\t\t\t\t 4:Quitter"<<endl;
				cin>>choix;
				menu_general(c,choix,choix2);
			}
		fichier.close();
	}
}

//--------------création d'un compte pour un client donné avec son Identificateur----------------

void CreerCompte()
{
	int Crech;
	char o,ch;
	time_t currenttime=time(0);
	tm* ltm=localtime(&currenttime);
	cout<<"Taper l'id client que vous voulez le creer un compte."<<endl;
	cin>>Crech;
	ofstream fichier2("tp6projetCompte.txt", ios::out | ios::app);
		if(recherche(Crech)==1)
		{
			cout<<"Cet Client existe,vous pouvez le creer un compte."<<endl;
		}
		else
		{
			cout<<"Cet id n'existe pas"<<endl;
			CreerCompte();
		}
		cm.id_client=c1.id_client;
		cout<<"ID Client:"<<cm.id_client<<endl;	
		cout<<"Nom et Prenom de Client:"<<c1.nom<<" "<<c1.prenom<<endl;
		cout<<"ID Compte:";
		cin>>cm.id_compte;
		cout<<"Solde:";
		cin>>cm.solde;
		cout<<"La Date d'Ouverture:"<<endl;
		cout<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<"  //  "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
		//fichier2<<"ID_C  "<<"  ID_compte  "<<"Nom   "<<"\t      Prenom    "<<"\tSolde  "<<"\tLa Date d'Ouverture  "<<endl;
		fichier2<<cm.id_client<<"          "<<cm.id_compte<<"        "<<c1.nom<<"       "<<c1.prenom<<"     "<<cm.solde<<"DH      ";//<<cm.date_ouv<<endl;
		fichier2<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<"  //  "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
		cout<<"Vous voulez ajouter un compte pour un autre client o/n ??"<<endl;
		cin>>o;
		if(o=='o')
		{
			CreerCompte();
		}
		if(o=='n')
		{
			
			cout<<"Vous etes sure de quitter notre service a:OUI b:NON??"<<endl;
			cin>>ch;
			if(ch=='a')
			{	
				cout<<"A bientot !!"<<endl;
			}
			if(ch=='b')
			{
				system("cls");
				cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Bienvenue dans notre service Bancaire<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
				cout<<"\t\t\t\t\t 1:Gestion des clients."<<endl<<"\t\t\t\t\t 2:Gestion des comptes"<<endl<<"\t\t\t\t\t 3:Gestion des operations."<<endl<<"\t\t\t\t\t 4:Quitter"<<endl;
				cin>>choix;
				menu_general(c,choix,choix2);
			}
		}
		fichier2.close();
}
//-----------------pour chercher si l'id compte existe ou pas-----------------------
/*int recherche2 (int numrech)
{
 	ifstream fichier2 (" tp6projetCompte.txt", ios::in );
	if(fichier2)
	{   
		do
		{
			fichier2>>cm.id_client>>cm.id_compte>>c1.nom>>c1.prenom>>cm.solde;
			if (cm.id_compte==numrech)
			{
				fichier2.close();
				return 1;
			}
		}while(!fichier2.eof());
		fichier2.close();
		return -1;		
	}
}*/

//-------------------cette fontion nous permettons de consulter le solde d'un client donnee pas l'identificateur de son compte------------------------------
int checksolde()
{
	int rechs,cpt=0;
	string line;
	cout<<"Taper l'id compte que vous voulez consulter son solde."<<endl;
	cin>>rechs;
 	ifstream fichier2("tp6projetCompte.txt", ios::in );
	if(fichier2)
		{ 
			while(getline(fichier2,line))
			{
				fichier2>>cm.id_client>>cm.id_compte>>c1.nom>>c1.prenom>>cm.solde;
				if(cm.id_compte==rechs)
				{
					cout<<"cet id compte existe vous pouvez consulter son solde"<<endl;
					fichier2>>cm.id_client>>cm.id_compte>>c1.nom>>c1.prenom>>cm.solde;
					cout<<cm.id_compte<<"  "<<c1.nom<<"  "<<c1.prenom<<endl;
					cout<<"le solde de ce compte est:"<<cm.solde<<"DH"<<endl;
					cout<<"voulez vous consulter le solde d'un autre compte o/n ??"<<endl;
					cin>>c;
					if(c=='o' || c=='O')
					{
						checksolde();
					}
					if(c=='n' || c=='N')
					{
						cout<<"A bientot"<<endl;
						break;
					}
				}
			}
		}		
}
		
//-----------------------------retirer un montant choisi-----------------
void retirer()
{
	int id_cm;
	int ret;
	int count=0;	
	string line;
	cout<<"taper l'id compte a retirer un montant"<<endl;
	cin>>id_cm;
	ifstream fichier2("tp6projetCompte.txt", ios::in);
	ofstream tempRet("tempR.txt",ios::out | ios::app);
	if(fichier2 && tempRet)
	{	
			while(getline(fichier2,line))
			{

				fichier2>>cm.id_client>>cm.id_compte>>c1.nom>>c1.prenom>>cm.solde;
				if(cm.id_compte!=id_cm)	
				{
					tempRet<<cm.id_compte<<"  "<<c1.nom<<"  "<<"  "<<c1.prenom<<"  "<<cm.solde<<"DH"<<endl;
				}
				if(cm.id_compte==id_cm)
				{
					cout<<"cet id compte existe vous pouvez retirer un montant"<<endl;
					fichier2>>c1.id_client>>cm.id_compte>>c1.nom>>c1.prenom>>cm.solde;
					cout<<cm.id_compte<<"  "<<c1.nom<<"  "<<c1.prenom<<endl;
					cout<<"le solde de ce compte est:"<<cm.solde<<"DH"<<endl;
			
				}
			}
				cout<<"taper le montant que vous voulez le retirer"<<endl;
				cin>>ret;
				if(ret<cm.solde)
				{
					cm.solde-=ret;
					tempRet<<cm.id_compte<<"  "<<c1.nom<<"  "<<"  "<<c1.prenom<<"  "<<cm.solde<<"DH"<<endl;
					cout<<"le solde actuel est:"<<cm.solde<<"DH"<<endl;
						cout<<"la retrait a ete bien effectue"<<endl;	
				}
				else
				{
					cout<<"Le Montant que vous avez choisi est impossible de le retirer"<<endl;
				}
		tempRet.close();
		fichier2.close();
	//	remove("tp6projetCompte.txt");
		rename("tempR.txt","tp6projetCompte");
	}
}
void ajouterMontant()
{
	int id_cm;
	int ajt;
	string line;
	cout<<"taper l'id compte a retirer un montant"<<endl;
	cin>>id_cm;
	ifstream fichier2("tp6projetCompte.txt", ios::in);
	ofstream tempAjt("tempajt.txt",ios::out | ios::app);
	if(fichier2 && tempAjt)
	{
			while(getline(fichier2,line))
			{
				fichier2>>cm.id_client>>cm.id_compte>>c1.nom>>c1.prenom>>cm.solde;
				if(cm.id_compte!=id_cm)
				{
					tempAjt<<cm.id_compte<<"  "<<c1.nom<<"  "<<"  "<<c1.prenom<<"  "<<cm.solde<<"DH"<<endl;
				}
				if(cm.id_compte==id_cm)
				{
					cout<<"cet id compte existe vous pouvez retirer un montant"<<endl;
					fichier2>>c1.id_client>>cm.id_compte>>c1.nom>>c1.prenom>>cm.solde;
					cout<<cm.id_compte<<"  "<<c1.nom<<"  "<<c1.prenom<<endl;
					cout<<"le solde de ce compte est:"<<cm.solde<<"DH"<<endl;
				}
			}
				cout<<"taper le montant que vous voulez ajoter a ce compte"<<endl;
				cin>>ajt;
				cm.solde+=ajt;
				tempAjt<<cm.id_compte<<"  "<<c1.nom<<"  "<<"  "<<c1.prenom<<"  "<<cm.solde<<"DH"<<endl;
				cout<<"le solde actuel est:"<<cm.solde<<"DH"<<endl;
	/*	tempAjt.close();
		fichier2.close();
		remove("tp6projetCompte.txt");
		rename("tempajt.txt","temp6ProjetCompte");*/
		cout<<"l'ajout de montant a ete bien effectue"<<endl;	
	}
}
//-------------------------
void verser()
{
	int id_cm;
	int ver,vero;
	string line;
	cout<<"taper id compte a retirer un  montant"<<endl;
	cin>>id_cm;
	ifstream fichier2("tp6projetCompte.txt", ios::in);
	ofstream tempVer("tempV.txt",ios::out | ios::app);
	if(fichier2 && tempVer)
		{
		while(getline(fichier2,line))
			{
				fichier2>>cm.id_client>>cm.id_compte>>c1.nom>>c1.prenom>>cm.solde;
				if(cm.id_compte==id_cm)
				{
					cout<<"cet id compte existe vous pouvez verser un montant a un compte choisi"<<endl;
					fichier2>>c1.id_client>>cm.id_compte>>c1.nom>>c1.prenom>>cm.solde;
					cout<<cm.id_compte<<"  "<<c1.nom<<"  "<<c1.prenom<<endl;
					cout<<"le solde de ce compte est:"<<cm.solde<<"DH"<<endl;
					break;
				}
			}
				cout<<"taper le montant que vous voulez le verser"<<endl;
				cin>>ver;
				if(ver<cm.solde)
				{
					cm.solde-=ver;
					tempVer<<cm.id_compte<<"  "<<c1.nom<<"  "<<"  "<<c1.prenom<<"  "<<cm.solde<<"DH"<<endl;
					cout<<"le solde actuel de ce compte est:"<<cm.solde<<"DH"<<endl;
					cout<<"taper l'id compte que vous voulez verser le montant que vous avez choisi"<<endl;
					cin>>vero;
					while(getline(fichier2,line))
					{
						fichier2>>cm.id_client>>cm.id_compte>>c1.nom>>c1.prenom>>cm.solde;
						if(cm.id_compte==vero)
						{
							cout<<"cet id compte existe,on va le verser le montant"<<endl;
							fichier2>>c1.id_client>>cm.id_compte>>c1.nom>>c1.prenom>>cm.solde;
							cm.solde+=ver;	
							cout<<cm.id_compte<<"  "<<c1.nom<<"  "<<c1.prenom<<endl;
							cout<<"le solde de ce compte est:"<<cm.solde<<"DH"<<endl;
							cout<<"e versement a ete bien effectuer"<<endl;
						}
					}
				}
				else
				{
					cout<<"Le Montant que vous avez choisi est impossible de le verser"<<endl;
				}
		}
	}
//------------la fonction main--------------
int main()
{ 
	ofstream fichier (" tp6projet.txt", ios::out | ios::app );
	if(fichier )
	{
		cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Bonjour Dans Notre Service Bancaire<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
		system("COLOR 3f");
		cout<<"*********************************************Menu General***********************************************"<<endl;
		cout<<"\t\t\t\t\t 1:Gestion des clients."<<endl<<"\t\t\t\t\t 2:Gestion des comptes"<<endl<<"\t\t\t\t\t 3:Gestion des operations."<<endl<<"\t\t\t\t\t 4:Quitter"<<endl;
		cin>>choix;
		menu_general(c,choix,choix2);
		fichier.close();		
	}
	else
	{
	cerr<<"impossible douvirir le fichier"<<endl;
	}
	return 0;	

}
