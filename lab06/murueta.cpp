#include <iostream>
#include <list>
using namespace std;

void inserthash(list<int>hash[], int num, int size){
    int mod;
    mod = num % size;
    if(size != 0){
        hash[mod].push_front(num);
    }
}
void searchhash(list<int>hash[], int num, int size){
    int mod = num % size;
    int k = 0;
    bool found = false;
    for(list<int> :: iterator i = hash[mod].begin(); i != hash[mod].end(); i++){
        if(*i == num){
            cout<<num<<":FOUND_AT"<<mod<<","<< k<<";"<<endl;
            found = true;
        }
        k++;
    }
    if(!found){
        cout << num <<":NOT_FOUND;"<<endl;
    }
}
void deletehash(list<int>hash[], int num, int size){
    int mod = num % size;
    int k = 0;
    bool found = false;
    for(list<int> :: iterator i = hash[mod].begin(); i != hash[mod].end(); i++){
        if(*i == num){
            hash[k].erase(i);
            cout << num << ":DELETED;" << endl;
            found = true;
            break;
        }
        k++;
    }
    if(!found){
        cout << num <<":DELETE_FAILED;"<< endl;
    }
}
void printhash(list<int>hash[], int size){
    for(int i = 0; i < size; i++){
        cout << i << ":";
        for(list<int> :: iterator g = hash[i].begin(); g != hash[i].end(); g++){
            cout << *g << "->";
        }
        cout << ";" << endl;
    }
}

int main(int argc, const char* argv[]){
    int size;
    char func;
    int num;
    cin >> size;
    list<int>hash[size];
    while(func != 'e'){
        cin >> func;
        if (func == 'i'){
            cin >> num;
            inserthash(hash, num, size);
        }
        if (func == 's'){
            cin >> num;
            searchhash(hash, num, size);
        }
        if (func == 'o'){
            printhash(hash, size);
        }
        if (func == 'd'){
            cin >> num;
            deletehash(hash, num, size);
        }
    }
    return 0;
}