#include<iostream>

using namespace std;

int main(int argc,char *argv[]){
        int N = argc-1;
        
        double sum = 0 ;
    
        if(N==0){  
            cout << "Please input numbers to find average." ;
        }else{  for (int i = 1; i < argc; i++)
        {
            sum += atof(argv[i]) ;

        }
        double avg = sum/N ;
    cout << "---------------------------------\n" ;
    cout << "Average of " << N <<" numbers = " << avg <<endl;
    cout << "---------------------------------" ;
    } 
    return 0;
}
