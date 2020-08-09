#include "HT.h"
#include <cstring>
#include <iostream>
using namespace std;

HT::HT()
{
    h=0;
    temp1=0;
    temp2=0;
    counter=0;
}

HT::HT(int k)
{
    temp1=0;
    temp2=0;
    counter=0;
    h=k*2;  ///<-Δημιουργεια ενος πινακα 2 φορες μεγαλυτερος απο τον αρχικο  ωστε να γινετε σωστα ο κατακερματισμος
    ht=new string [h];
    for(int i=0;i<h;i++)
    {
        ht[i][0]=' ';     ///<-εκχωρηση σε ολο τον πινακα τον κενο
    }
}

void HT::Insert(string k)  ///<-Παιρνει καθε φορα μια λεξη να την κατακερματιση
{
    int b=0;
    bool flag=1;
    for(int i=0;k[i]!='\0';i++)
    {
        b=b+fragmentation(k[i]);  ///<-Στελνουμε εναν εναν τους χαρακτηρε στην συναρτηση ωστε να μας επισταφει ο κωδικως  που ειχουν στον πινακα ascii
    }
    if(counter==0)
        temp1=b;
    else if(counter==1)
        temp2=b;
    else
    {
        //temp2=b;
        b=b+temp1;
        temp1=temp2;
        temp2=b;

    }
    counter++;

    while(b>h)   ///<-Μια while  η οποια θα παιρνει το ακεραιο υπολοιπο ωσπου το αποτελεσμα που εχει επιστεψη απο την συναστηση να ειναι μικροτερο του μεγεθους του πινακα
    {
        b%=h;
    }
    while (flag)   ///<-Η While  αυτη θα κανει θα σταματαει μονο αφου κανει Insert την λεξη
    {
        if (ht[b][0]==' ') ///<-Ελενχη αν στην συγκεκτιμενη θεση του πινακα υπαχει ειδη καποια αλλη λεξη η ειναι κενη εστε να την υποδεχτη
        {
            ht[b]=k;  ///<-Αντιγραφω την λεξη με την ετοιμη συναρτηση
            flag=0;      ///<-Αφου αντιγραφει η λεξη σταματαω την επαναληψη
            //cout<<b<<ht[b]<<endl;
        }
        b++;
        if(b>=h+1)  ///<-Η IF αυτη ελενχει ανα το b εχει φτασει το μεγεθος του πινακα +1 ωστε να μπορει να ξεκεινησει απο την αρχη
            b=0;
    }
}

bool HT::Search(string k)///<-Δεχομαστε παλι καθε φορα μια λεξη ξεχωσιστα
{
    int q=0;
    int b=0;
    bool flag=1;
    for(int i=0;k[i]!='\0';i++)///<-Εδω ειναι η ειδα συναρτηση με πανω η οποια μας επειστεφει τους κωδικους απο τον πινακα ASSCI καθε γραμματος και το προσθετουμε
    {
        b+= fragmentation(k[i]);
    }
    if(counter==0)
        temp1=b;
    else if(counter==1)
        temp2=b;
    else
    {
        //temp2=b;
        b=b+temp1;
        temp1=temp2;
        temp2=b;

    }
    counter++;

    while(b>h)///<-Ακριβως ιδια while με πανο
    {
        b%=h;
    }

    while(flag)///<-Η η οποια δεν τερματιζει ποτε με το flag της
    {
        if(ht[b]==k) ///<-Η IF αυτη ελενχει αν η δυο λεξεις ειναι ιδιες ξεκεινωντας απο το b το οποιο εχει επιστραφει απο την συναρτηση κατακερματισμου
            return true; ///<-Επιστρεφει TRUE αν η λεξη ειναι ιδια
        b+=1;///<-Το b οπως και πριν αυξανεται καθε φορα κατα 1
        if (b==h+1) ///<-Αν φτασουμε το μεγεθος του πινακα το b ξεκειναει παλι απο την αρχη
            b=0;
        q++;///<-Μια νεα μεταβλητη q η οποια μετραει ξεκειναει απο το 0 και εκτινεται μεχτι το μεγεθος του πινακα
        if(q==h+1)///<-Ελενχετε ανα το q  εχει φτασει το μεγεθος του πινακα το οποιο σημενει οτι δεν εχει βρε την λεξη με αποτελεσμα να επιστρεφεται η τιμη false
            return false;
    }
}

int HT::fragmentation(char k)  ///<-ΜΙα συναρτηση η οποια θα δεχεται εναν εναν τους χαρακτηρες τηε καθε λεξης και με την βοηθεια μια switch case θα αναζειτα τον χαρακτηρα και θα επιστεφει τον κωδικο απο τον πινακα ASCII απου βρισκεται
{
    int b=0;
    switch(k)
    {
        case 'a':
            b=1;
            break;
        case 'b':
            b=2;
            break;
        case 'c':
            b=3;
            break;
        case 'd':
            b=4;
            break;
        case 'e':
            b=5;
            break;
        case 'f':
            b=6;
            break;
        case 'g':
            b=7;
            break;
        case 'h':
            b=8;
            break;
        case 'i':
            b=9;
            break;
        case 'j':
            b=10;
            break;
        case 'k':
            b=11;
            break;
        case 'l':
            b=12;
            break;
        case 'm':
            b=13;
            break ;
        case 'n':
            b=14;
            break;
        case 'o':
            b=15;
            break;
        case 'p':
            b=16;
            break;
        case 'q':
            b=17;
            break;
        case 'r':
            b=18;
            break;
        case 's':
            b=19;
            break;
        case 't':
            b=20;
            break;
        case 'u':
            b=21;
            break;
        case 'v':
            b=22;
            break;
        case 'w':
            b=23;
            break;
        case 'x':
            b=24;
            break;
        case 'y':
            b=25;
            break;
        case 'z':
            b=26;
            break;

    }
    return b;
}

HT::~HT()///<-Κενος καταστροφεας
{
    delete [] ht;
}
