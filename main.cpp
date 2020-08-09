#include "TreeNode.h"///ΚΛΑΣΗ TreeNode ΠΟΥ ΑΝΑΠΑΡΙΣΤΑ ΕΝΑΝ ΚΟΜΒΟ ΔΕΝΤΡΟΥ
#include "BTS.h"///ΚΛΑΣΗ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ
#include "AVLtree.h"///ΚΛΑΣΗ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ AVL
#include <ctime>  ///<-Βιβλιοθηκη για τις συναστησεις χρονου
#include "HT.h"   ///<-κλαση του πινακα κατακερματισμου
#include <fstream> ///<-Βιβλιοθηκη για το ανοιγμα και το κλεισιμο του αρχειου
#include <cstring>  ///Βιβλιοθηκη για το χειρισμο ετοιμων συναρτησεων (char,string)
#include <cctype>   ///Βιβλιοθηκη για την χρηση ετοιμης συναρτησης η οποια  μετατρεπει τους κεφαλαιους χαρακτηρες σε πεζους
#include <sstream>
#define E 260000    ///<-Προκαθοριμος μεγεθους πινακων
#define Q 10000
#include <iostream>
using namespace std;


///ΣΥΝΑΡΤΗΣΗ ΕΞΑΛΗΨΗΣ ΚΕΝΩΝ ΑΠΟ ΜΙΑ ΣΥΜΒΟΛΟΣΕΙΡΑ
string removeSpaces(string input)
{
  int length = input.length();
  for (int i = 0; i <= length; i++) {
     if(input[i] == ' ')
        input.erase(i, 1);
  }
  return input;
}


int main()
{
    string s,*word=new string[E];        ///Δηλωσεις μεταβλητων
    int g=0,j,k,i;
    double c_ht1,c_ht2,c_BTS1,c_BTS2,c_BTS3,c_AVL1,c_AVL2,c_AVL3,c_AVL_succesor,c_BTS_succesor;///ΜΕΤΑΒΛΗΤΕΣ ΠΟΥ ΠΕΡΙΕΧΟΥΝ ΤΟ ΧΡΟΝΟ ΕΚΤΕΛΕΣΗΣ ΓΙΑ ΚΑΘΕ ΔΟΜΗ ΚΑΙ ΓΙΑ ΚΑΘΕ ΔΙΑΔΙΚΑΣΙΑ ΑΥΤΗΣ


    ifstream is("small-file.txt",ios::in); ///<-Aνοιγμά αρχειου

    i=0;
    do
    {
        g++;///
        is >> s;
        word[i]=s ;   ///<-Πινακας string  στο οποιο θα αποθηκευονται οι λεξεις που διαβαζονται απο το αρχειο(μαζι με τα σημεια στιξης)
        i++;
    }
    while (!is.eof()&&i<E);

    is.close();  /// <-Κλεισιμο αρχειου

    for(i=0 ; i<E ; i++)
    {

        ///ΑΝΤΙΚΑΤΑΣΤΑΣΗ ΟΛΩΝ ΤΩΝ ΠΕΡΙΤΤΩΝ ΣΥΜΒΟΛΩΝ ΜΕ ΤΟ ΚΕΝΟ, ΓΙΑ ΚΑΘΕ ΣΥΜΒΟΛΟΣΕΙΡΑ
        k=0;
        s=word[i];
        for(j=0 ; s[j]!='\0' ; j++)
        {
            if ( (s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z') )
            {
                word[i][j]=s[j];
                k++;
            }
            else
                word[i][j]=' ';
        }
        ///ΔΙΑΓΡΑΦΗ ΟΛΩΝ ΤΩΝ ΚΕΝΩΝ
        for(j=0;j<word[i].length();j++)
        {
            word[i]=removeSpaces(word[i]);
        }

    }


    clock_t time_req;///ΧΡΟΝΟΣ ΜΕΤΑΒΛΗΤΗ


                                                ///ΔΟΜΗ HASHTABLE
    HT a(g);

    time_req = clock();///ΧΡΟΝΟΣ ΑΡΧΗ

    for(i=0;i<g;i++)
    {
        a.Insert(word[i]); ///<-Insert στον πινακα κατακερματισμου
    }

    time_req = clock() - time_req;///ΧΡΟΝΟΣ ΤΕΛΟΣ
    c_ht1=(double)time_req/CLOCKS_PER_SEC;

    a.setcounter(0);///ΑΡΧΙΚΟΠΟΙΗΣΗ
    a.settemp1(0);
    a.settemp2(0);

    time_req=clock();///ΧΡΟΝΟΣ ΑΡΧΗ

    for(i=0;i<Q;i++)
    {
        a.Search(word[i]);///<-Η Search του πινακα κατακερτματισμου η οποια εμφανιζει "YES" οταν υπαρχει η λεξη και "NO" στην αντιθετη περιπτωση
    }

    time_req = clock() - time_req;///ΧΡΟΝΟΣ ΤΕΛΟΣ
    c_ht2=(double)time_req/CLOCKS_PER_SEC ;

                                                   ///ΔΟΜΗ AVLtree


    AVLtree AVL_binary_tree;

    time_req=clock();///ΧΡΟΝΟΣ ΑΡΧΗ

    for(i=0;i<g;i++)
    {
        AVL_binary_tree.head_AVL=AVL_binary_tree.insert(word[i],AVL_binary_tree.head_AVL);
    }
    time_req = clock() - time_req;///ΧΡΟΝΟΣ ΤΕΛΟΣ
    c_AVL1=(double)time_req/CLOCKS_PER_SEC;

    time_req=clock();///ΧΡΟΝΟΣ ΑΡΧΗ
    cout<<"                    inorder"<<endl;
    AVL_binary_tree.inOrder(AVL_binary_tree.head_AVL);///ΕΝΔΟΔΙΑΤΑΞΗ(ΑΤΙΣΤΕΡΑ , ΚΕΝΤΡΟ , ΔΕΞΙΑ)

    cout<<"                    preorder"<<endl;
    AVL_binary_tree.preOrder(AVL_binary_tree.head_AVL);///ΠΡΟΔΙΑΤΑΞΗ(ΚΕΝΤΡΟ , ΑΡΙΣΤΕΡΑ , ΔΕΞΙΑ)

    cout<<"                    postorder"<<endl;
    AVL_binary_tree.postOrder(AVL_binary_tree.head_AVL);///ΜΕΤΑΔΙΑΤΑΞΗ(ΑΡΙΣΤΕΡΑ , ΔΕΞΙΑ , ΚΕΝΤΡΟ)
    time_req = clock() - time_req;///ΧΡΟΝΟΣ ΤΕΛΟΣ
    c_AVL_succesor=(double)time_req/CLOCKS_PER_SEC;

    time_req=clock();///ΧΡΟΝΟΣ ΑΡΧΗ

    for(int i=0;i<Q;i++)
    {
        AVL_binary_tree.search(AVL_binary_tree.head_AVL,word[i]);///ΑΝΑΖΗΤΗΣΗ ΜΙΑΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΤΟΥ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ
    }
    time_req = clock() - time_req;///ΧΡΟΝΟΣ ΤΕΛΟΣ
    c_AVL2=(double)time_req/CLOCKS_PER_SEC;

    time_req=clock();///ΧΡΟΝΟΣ ΑΡΧΗ

    for(i=0;i<Q;i++)
    {
        AVL_binary_tree.head_AVL=AVL_binary_tree.deleter(AVL_binary_tree.head_AVL,word[i]);/// ΔΙΑΓΡΑΦΗ ΜΙΑΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΑΠΟ ΤΟ ΔΥΑΔΙΚΟ ΔΕΝΤΡΟ ΑΝΑΖΗΤΗΣΗΣ AVL
    }
    time_req = clock() - time_req;///ΧΡΟΝΟΣ ΤΕΛΟΣ
    c_AVL3 =(double)time_req/CLOCKS_PER_SEC;


                                      ///ΔΟΜΗ ΑΠΛΟΥ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ


    BTS binary_tree;///ΑΝΤΙΚΕΙΜΕΝΟ BTS (ΑΠΛΟΥ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ)

    time_req=clock();///ΧΡΟΝΟΣ ΑΡΧΗ

    for(i=0;i<g-1;i++)
    {
        binary_tree.insert(word[i]);///ΕΙΣΑΓΩΓΗ ΟΛΩΝ ΤΩΝ ΛΕΞΕΩΝ ΤΟΥ ΚΕΙΜΕΝΟΥ ΣΤΗ ΔΟΜΗ ΤΟΥ BTS
    }

    time_req = clock() - time_req;///ΧΡΟΝΟΣ ΤΕΛΟΣ
    c_BTS1=(double)time_req/CLOCKS_PER_SEC;

    time_req=clock();///ΧΡΟΝΟΣ ΑΡΧΗ
    cout<<"                    inorder"<<endl;
    binary_tree.inOrder(binary_tree.head);///ΕΝΔΟΔΙΑΤΑΞΗ(ΑΤΙΣΤΕΡΑ , ΚΕΝΤΡΟ , ΔΕΞΙΑ)

    cout<<"                    preorder"<<endl;
    binary_tree.preOrder(binary_tree.head);///ΠΡΟΔΙΑΤΑΞΗ(ΚΕΝΤΡΟ , ΑΡΙΣΤΕΡΑ , ΔΕΞΙΑ)

    cout<<"                    postorder"<<endl;
    binary_tree.postOrder(binary_tree.head);///ΜΕΤΑΔΙΑΤΑΞΗ(ΑΡΙΣΤΕΡΑ , ΔΕΞΙΑ , ΚΕΝΤΡΟ)
    time_req = clock() - time_req;///ΧΡΟΝΟΣ ΤΕΛΟΣ
    c_BTS_succesor=(double)time_req/CLOCKS_PER_SEC;


    time_req=clock();///ΧΡΟΝΟΣ ΑΡΧΗ
    for(int i=0;i<Q;i++)
    {
        binary_tree.search(binary_tree.head,word[i]);///ΑΝΑΖΗΤΗΣΗ ΜΙΑΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΤΟΥ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ
    }
    time_req = clock() - time_req;///ΧΡΟΝΟΣ ΤΕΛΟΣ
    c_BTS2=(double)time_req/CLOCKS_PER_SEC;

    time_req=clock();///ΧΡΟΝΟΣ ΑΡΧΗ

    for(i=0;i<Q;i++)
    {
        binary_tree.head=binary_tree.deleter(binary_tree.head,word[i]);/// ΔΙΑΓΡΑΦΗ ΜΙΑΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΑΠΟ ΤΟ ΔΥΑΔΙΚΟ ΔΕΝΤΡΟ ΑΝΑΖΗΤΗΣΗΣ
    }
    time_req = clock() - time_req;///ΧΡΟΝΟΣ ΤΕΛΟΣ
    c_BTS3=(double)time_req/CLOCKS_PER_SEC;


                                  ///ΕΜΦΑΝΙΣΗ ΤΩΝ ΧΡΟΝΩΝ
    cout<<c_AVL_succesor<< " seconds" <<" for inorder-preorder-postorder in AVLtree"<< endl;///ΧΡΟΝΟΣ
    cout<<c_BTS_succesor<< " seconds" <<" for inorder-preorder-postorder in BINARY SEARCH TREE"<< endl<<endl;///ΧΡΟΝΟΣ
    cout<<c_ht1<< " seconds" <<" for insert in HASHTABLE"<< endl;///ΧΡΟΝΟΣ
    cout<<c_AVL1<< " seconds" <<" for insert in AVL BINARY SEARCH TREE"<< endl;///ΧΡΟΝΟΣ
    cout<<c_BTS1<< " seconds" <<" for insert in BINARY SEARCH TREE"<< endl<<endl;///ΧΡΟΝΟΣ
    cout<<c_ht2<< " seconds" <<" for search in HASHTABLE"<< endl;///ΧΡΟΝΟΣ
    cout<<c_AVL2<< " seconds" <<" for search in AVL BINARY SEARCH TREE"<< endl;///ΧΡΟΝΟΣ
    cout<<c_BTS2<< " seconds" <<" for search in BINARY SEARCH TREE"<< endl<<endl;///ΧΡΟΝΟΣ
    cout<<c_AVL3<< " seconds" <<" for delete in AVL BINARY SEARCH TREE"<< endl;///ΧΡΟΝΟΣ
    cout<<c_BTS3<< " seconds" <<" for delete in BINARY SEARCH TREE"<< endl<<endl;///ΧΡΟΝΟΣ
    cout<<"Generally Hahtable run for "<<c_ht1+c_ht2<<" seconds"<<endl;
    cout<<"Generally AVLtree run for "<<c_AVL1+c_AVL2+c_AVL3<<" seconds"<<endl;
    cout<<"Generally Binary search tree (BTS) run for "<<c_BTS1+c_BTS2+c_BTS3<<" seconds"<<endl;



    return 0;
}
