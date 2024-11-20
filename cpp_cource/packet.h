// Programming Fundmentals End Semester Project
// FIREWALL


using namespace std;

struct packet { // declaring struct to store packets
string src;
string dst;
string protocol;
string data;
int no_of_packets;
};

struct rules{ //declaring struct to store rules  
string src;
string dst;
string pro;
string action;
int rule_no;

};
 packet noofpack;  
rules applyrules[100];   //variable of type rules
packet pack[100];     //variable of type packets
int k = 0;    //global variable
int l =0;  // global variable



//function to store rules in struct
void storerules( string& rulestext , int i)     //taking by refrence
{
regex rulepattern(R"(ALLOW|DENY)");          //using regex to find "ALLOW" or "DENY" in the line
smatch match;                                 //use to store the similar items
if(regex_search(rulestext,match,rulepattern))     //use to compare rulepattern and ruletext and store the match in smatch variable
{
      string act = match.str();      
      applyrules[i].action = act;
}

int posrule_no = rulestext.find(" ");    
string sub_rule_no = rulestext.substr(0,posrule_no);
applyrules[i].rule_no = stoi(sub_rule_no);            //find the rule no

int pos_src = rulestext.find("SRC ")+4;      //finding "SRC" in rules file
string sub_src = rulestext.substr(pos_src,rulestext.find(" ",pos_src)-pos_src);
  applyrules[i].src = sub_src ;    //storing source IP
 
int pos_dst = rulestext.find(" DST ")+5;     //finding "DST" in rules file
string sub_dst = rulestext.substr(pos_dst,rulestext.find(" ",pos_dst)-pos_dst);
applyrules[i].dst = sub_dst ;        //storing destination IP

int pos_pro = rulestext.find(" PRO ")+5;     //finding "PRO" in rules file
string sub_pro = rulestext.substr(pos_pro,rulestext.find(" ",pos_pro)-pos_pro);
applyrules[i].pro = sub_pro ;       //storing protocol

}

void rulefile(){        //function to read and store rules
    string rulestext;
    ifstream rules_file("C:/Users/ABS/Desktop/inputrules.txt");
    
    while(getline(rules_file,rulestext)) 
    {
        
       
        storerules(rulestext,l);   
        l++;

    }
   
}



void packets(){               //function to store packet elements in struct

string  text , line;      
    ifstream input("C:/Users/ABS/Desktop/packets.txt");
    while(getline(input,line)){
     text += line;      //storing all packets in text
    }
    
    int start = 0;
    int i =0;
    int j =0;
    
    while( i=1){        //staring an infinity loop
      
      
    start = text.find('[',start);    
    if(start != string::npos){          //if '[' is found then the if condition will be implemented
    int end = text.find(']',start);
    if(end != string::npos){          //if ']' is found then the if condition will be implemented
    string pk = text.substr(start,end-start+1);       //for storing single packet in pk
    noofpack.no_of_packets++;
    cout << "\npacket " << noofpack.no_of_packets<<endl;
    cout << "\n" <<  pk << endl;
     
  
    //find and store the source ip
    int pos = pk.find("SRC:")+4;       
    pack[k].src = pk.substr(pos,pk.find(";",pos)-pos);
    cout << " The source is   =   " << pack[k].src <<  endl;

    //find and store the destination ip 
     pos = pk.find("D")+4;
    pack[k].dst = pk.substr(pos,pk.find(';',pos)-pos);
    cout << "The Destination is   =  " << pack[k].dst << endl;

    //find and store the protocol 
     pos = pk.find("O:")+2;
     pack[k].protocol = pk.substr(pos,pk.find(';',pos)-pos);
     cout << " the protocol is  =   "<< pack[k].protocol<< endl;

    //find and store data 
    pos =pk.find_last_of(';')+1;
    pack[k].data = pk.substr(pos, pk.find(']',pos)-pos);
    cout <<  "The data is   =   "<<pack[k].data<< endl;



    k++;

  





    start = end+1;   //initiate the same process for next packet
    }
    }else   //if '[' is not found then the loop will break
    break;
    }


    input.close();


}




void compare()   //used to compare rules and packets
{

ofstream outputfile("C:/Users/ABS/Desktop/result.dat");
      outputfile << "  ______________              \n";
      outputfile << "  | ____________|                    \n";
      outputfile << "  | |                  \n";
      outputfile << "  | |                  \n";
      outputfile << "  | |__________                 \n";
      outputfile << "  |  __________|         \n";
      outputfile << "  | |              \n";
      outputfile << "  | |                 \n";
      outputfile << "  | |  irewall             \n";
      outputfile << "  |_|              \n";
      outputfile << " \n\n\n\n\n";
   
if(!outputfile.is_open())
{
  cerr << "error while opning the file!\n";
}
  for(int i=0;i<k;i++)
  {
    bool packetblocked = true;
  for(int j=0;j<l;j++)
  {
    //for ranging
    int o = applyrules[j].dst.find("-");   
   if(o != string::npos && pack[i].src == applyrules[j].src && pack[i].protocol == applyrules[j].pro)
   {
    packetblocked = false;
    
    int u = applyrules[j].dst.find_last_of(".")+1;
      int  brange = stoi(applyrules[j].dst.substr(u,applyrules[j].dst.find("-",u)-u));  //access the no before "-"

      int arange = stoi(applyrules[j].dst.substr(applyrules[j].dst.find("-")+1));  //access the no after "-"

      int p = pack[i].dst.find_last_of(".")+1;  //to store the no before "-"
      int rp = stoi(pack[i].dst.substr(p)) ;    //to store the no after "-"

         if(brange<=rp && arange>=rp)      //if the ip is in range than this if condition will be used
         {
          if(applyrules[j].action == "ALLOW"){
                 outputfile <<  "SRC " <<pack[i].src <<  " DST " << pack[i].dst << " PRO " << pack[i].protocol << " ALLOW "<< j+1 << endl;
                
         }
         else if(applyrules[j].action == "DENY")
           {

            outputfile <<  "SRC " <<pack[i].src <<  " DST " << pack[i].dst << " PRO " << pack[i].protocol << " DENY "<< j+1 << endl;
      
           }
         }
         else
         {

          outputfile <<  "SRC " <<pack[i].src <<  " DST " << pack[i].dst << " PRO " << pack[i].protocol << " DENY "<< j+1 << endl;
      
         }

   }

  if(pack[i].src == applyrules[j].src && pack[i].dst == applyrules[j].dst && pack[i].protocol == applyrules[j].pro)
  {
    packetblocked = false;
    if(applyrules[j].action == "ALLOW")
    {
      outputfile <<  "SRC " <<pack[i].src <<  " DST " << pack[i].dst << " PRO " << pack[i].protocol << " ALLOW "<< j+1 << endl;
 
    }
    else if(applyrules[j].action == "DENY")
    {

      outputfile <<  "SRC " <<pack[i].src <<  " DST " << pack[i].dst << " PRO " << pack[i].protocol << " DENY "<< j+1 << endl;

    }
  
  }
  
  }
  if(packetblocked == true)
  {

      outputfile <<  "SRC " <<pack[i].src <<  " DST " << pack[i].dst << " PRO " << pack[i].protocol << " DENY "<< "unspecified " << endl;

  }

  
  }
 
outputfile << "\n\n\n\n\n\n\n_______________________________________________________________________________________________________\n";
outputfile << "\n\n\n\nThanks for using this fire wall \n"
<< "If you find any bugs in this code plz contact to :\n"
<< "Email : bilalxxxxx@gmail.com \n"
<< "Phone no : +92 0000-0000-000\n"
<< "Created by :       MUHAMMAD BILAL       MUHAMMAD MUSA             MUHAMMAD HUSAIN ZAFAR\n";

outputfile.close();




}