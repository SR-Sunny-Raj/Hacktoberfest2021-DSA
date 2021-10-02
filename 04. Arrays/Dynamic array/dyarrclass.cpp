#include<iostream>
using namespace std;

class dynamicarray {

    int *data;
    int nextindex;
    int capacity;

    public:
    
    dynamicarray(){
        data=new int[5];
        nextindex=0;
        capacity = 5;
    }

    void add(int element){

        if(nextindex==capacity)
        {
            int *newdata= new int[capacity * 2];
            for(int i=0; i<capacity; i++)
            newdata[i]=data[i];

            delete [] data;
            data = newdata;
        }

        data[nextindex]=element;
        nextindex++;
    }

    int get(int i){
        if(i<nextindex)
        return data[i];
        else
        return -1;
    }

    void add(int i, int element){
       if(i<nextindex)
        data[i]=element;

        else if(element == nextindex)
        add(element);

        else
        return;
    }

    void print(){
        for(int i=0;i<nextindex;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
    
    //self build Copy constructor

    dynamicarray(dynamicarray const &d){
        this->data=new int[d.capacity];
        
        for(int i=0;i<d.nextindex;i++)
        this->data[i]=d.data[i];

        this->capacity=d.capacity;
        this->nextindex=d.nextindex;
    }

    void operator=(dynamicarray const &d){
        this->data=new int[d.capacity];
        
        for(int i=0;i<d.nextindex;i++)
        this->data[i]=d.data[i];

        this->capacity=d.capacity;
        this->nextindex=d.nextindex;
    }


};