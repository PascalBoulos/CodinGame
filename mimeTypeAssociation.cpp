#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    string EXT; // file extension
    string MT; // MIME type.
    map<string,string> links;
    for (int i = 0; i < N; i++) {

        cin >> EXT >> MT; cin.ignore();
        transform(EXT.begin(),EXT.end(),EXT.begin(),::tolower);
        links[EXT]=MT;
    }
    
    
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        
        
        int pos=FNAME.rfind(".");
        if(pos!=string::npos){
            FNAME=FNAME.substr(pos+1,FNAME.length()-pos-1);
        }
        else{
            FNAME="";
        }
        transform(FNAME.begin(),FNAME.end(),FNAME.begin(),::tolower);
        try{
            cout<<links.at(FNAME)<<endl;
        }
        catch(...){
            cout<<"UNKNOWN"<<endl;
        }
    
    }
}
