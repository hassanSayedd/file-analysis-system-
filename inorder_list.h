using namespace std;
typedef string ListElemType;

class inorder_list{
	public:
	inorder_list();
	bool Insert(ListElemType &e,int Line); //insert passed word
	bool First(ListElemType &e);        //retrive first word in linked list
	bool Next(ListElemType &e);         //retrive next word in linked list 
	int WordCount();                  //count #words in file
	double DistCount();                  //count #distinct word in file
	void CharCount(const double &NumberOfChar);  //count #charachter in file
	void FrequentWord();                 //retrive most frequent word
	void CountWord(ListElemType &e); //count h.m passed word appears
	void Starting(ListElemType &e);                    //lesa msh fahmha
	void Containing(ListElemType &e);   //count #word that containg passed chars
	void Search( ListElemType &e); //search on words that containing passed chars
	void Print();
	//~inorder_list();
	private:
	struct Node;
	typedef Node* Link;
	struct Node{
		ListElemType Elem;
		int Line;
		Link Next;
	};
	Link Head;
	Link Tail;
	Link Current;
	Link Pred;
	
};