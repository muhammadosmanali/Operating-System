#include <iostream>
using namespace std;


class node {
	public:
		int data;
		node *next;
		node();
		node(int v);
};


class LL {

	private:
		node * head;
        node * headProcess;
        node * headBlockNumber;
		int totalMemory;
        int blockSize;
        int totalBlock;
    public:
		LL();
	    int AllocatedMemoryIndex();
		void insert(node *& head,int val);
		void insertProcess(int val);
		void inputRequirements(int totalMemory,int blockSize,int totalBlock);
		void print();
};

node::node(){
	this->data=0;
	this->next=NULL;

}
node::node(int v){
	this->data=v;
	this->next=NULL;
}
LL::LL(){
	head=NULL;
    headProcess=NULL;
    headBlockNumber=NULL;

}
void LL::insert(node *& hd,int val){
	node *np;
	np=new node();
	np->data=val;
	np->next=NULL;
	if(hd==NULL){
		hd=np;
	}
	else{
		node *t=hd;
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=np;
	}

}
void LL::inputRequirements(int totalMemory,int blockSize,int totalBlock){
    this->totalMemory=totalMemory;
    this->blockSize=blockSize;
    this->totalBlock=totalBlock;

    int memoryCreated=0;
    for(int i = 0; i < totalBlock; i++){
        if(memoryCreated>=totalMemory){
            break;
        }
        insert(head,blockSize);
        memoryCreated+=blockSize;
    }

}

void LL::insertProcess(int val){
    insert(headProcess,val);
    node *t;
    t=head;
    int insertedBlockNumber=0;
    while(t != NULL){
        if(val <= t->data){
            t->data=t->data-val;
            insertedBlockNumber=1;
            break;
        }
        t=t->next;
    }
    insert(headBlockNumber,insertedBlockNumber);
}

void LL::print(){
	node *t,*tmp,*m;
    m=head;
    t=headProcess;
    tmp=headBlockNumber;

    if(headProcess == NULL || head == NULL){
		cout<<" empty node";
	}
	else{
        int index = 0;
        int totalInternalFragmentation = 0;
        int totalExternalFragmentation = 0;

        cout<<"Process No.\tProcess Size\tBlock Allocated.\tInternal Fragmentation"<<endl;
		while(t != NULL) { 
		    index++;
            if(tmp->data==0){
                cout<<"   "<<index<<"\t\t    "<<t->data<<"\t\t      No\t\t\t-"<<endl;}

            else{
                cout<<"   "<<index<<"\t\t    "<<t->data<<"\t\t      Yes\t\t\t"<<m->data<<endl;
                 totalInternalFragmentation+=m->data;
                m=m->next;

            }
            tmp=tmp->next;
			t=t->next;
        }
        totalExternalFragmentation=this->totalMemory-(this->blockSize*this->totalBlock);
        cout<<"\nTotal Internal Fragmentation is "<<totalInternalFragmentation<<endl;
        cout<<"Total External Fragmentation is "<<totalExternalFragmentation<<endl;
	}
//}
}



int main() {
LL a;
int totalMemory, blockSize, totalBLock, n, process;
cout << "Enter the total Memory avaliable (in Bytes) = ";
cin >> totalMemory;
cout << "\nEnter the block size (int Bytes) = ";
cin >> blockSize;
cout << "\nNumber of Blocks avaliable in memory = ";
cin >> totalBLock;
a.inputRequirements(totalMemory, blockSize, totalBLock);
cout << "\nEnter the number of process = ";
cin >> n;
for(int i = 0; i < n; i++) {
    cout << "Enter memory required for process " << i+1 << " (in Bytes) = ";
    cin >> process;
    a.insertProcess(process);
    process = 0;
}
a.print();
}
