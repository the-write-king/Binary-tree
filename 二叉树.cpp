#include<iostream>

#include<vector> 
#include <Queue>
#include <stack> 
using namespace std;


    struct treenode
{
	int num;
	
	treenode* tleftchild;
	treenode* trightchild;
	
 };
 
 class tree
 {
 	public:
 		treenode *copyinorder; //采用中序遍历可直接找到左子树的最右节点 
 		treenode* findfathernode;//在节点删除时需要用到该节点的父节点，因而要对该节点的父节点进行查找记录 
 		tree();//构造函数，这里不用将其进行初始化，在 creattree里进行树的创建 
 		~tree();
		 int treenodenum();
		 void creattree(int num);
		 
	     treenode* returnroot()
	     {
	     	return treeroot;
		 }
	//	 void testtree(treenode* treeroot)
	//	 {
	//	 	cout<<treeroot<<endl;
	//	 	cout<<treeroot->trightchild<<endl;
	//	 	cout<<treeroot->trightchild->trightchild<<endl;
	//	 }
		 void preOrder(treenode * );    //前序遍历二叉树
	
         void inOrder(treenode * );        //中序遍历二叉树
         void postOrder(treenode * );    //后序遍历二叉树
         treenode* Find(treenode* treeroot,int data);//二叉树的查找 ,成功则返回该指针，否则返回NULL 
		 void Insert(treenode* treeroot,int data);//二叉树的插入 
		 void Delete(treenode* treeroot,int data);//二叉树的删除
		  
         void breadthFirstSearch(treenode* treeroot);//广度优先算法，又叫做层次遍历 
         void deepthFirstSearch(treenode* treeroot);//深度优先 
    private:
	    treenode* treeroot;		
 };
 
 
tree::tree( )
 {
 
   treeroot=NULL; 
    
 }
 
  tree::~tree()
 {
 	cout<<"test2`~"<<endl;
 }
 

 int tree::treenodenum()//这个主要是练习了vector，iterator的使用，无需在意 
 {
     int maxnodenum;
 	cout<<"输入总节点个数"<<endl;
	  
	 cin>>maxnodenum;//这个加上endl后发现会出现错误，不太清楚，后续跟进。。。。 
	  
 	vector<int> treenum(maxnodenum,0);
 	vector<int>::iterator ptree;
 	
 	for(ptree=treenum.begin();ptree!=treenum.end();ptree++)
 	{
	 
	 cout<<"inter num"<<endl;
	 cin>>*ptree;//cin>>*ptree>>endl;会发生错误。。。。 
	 
    }
 	for(ptree=treenum.begin();ptree!=treenum.end();ptree++)
 	cout<<"inter num\n"<<*ptree<<endl;
 	
 	return maxnodenum;
 }
 
 
 
 void tree::creattree(int val)//二叉树的建立 ，用递归可以实现二叉查找树，左儿子 < 父节点 < 右儿子。 
 {
 
   treenode *newnode =new treenode;
   newnode->num=val;
   newnode->tleftchild=NULL;
   newnode->trightchild=NULL;
   //cout<<"addr"<< <<endl;//输出treeroot的 地址值为0x400000，并不是传统意义上的NULL ,因而记得要给treeroot初始化 ，防止该指针指向不可访问的地址 
   
   if(!treeroot)//建议使用（!ptr）或（ptr） 之类的写法，这种写法在多数平台上都没歧义，只有一个统一的结果。 从此可以总结出，在不同的平台上，NULL可能会被定义为其他地址，当然这个地址都是非法不可访问的。
    {	
    	treeroot= newnode; 
    	
	}
	else
	{
		treenode *temnode=new treenode;//创建一个临时的根节点，以后没一个节点入树时都要从根节点开始判断
		temnode= treeroot; 
		while(temnode!=NULL)
		{
			if(newnode->num>temnode->num)//  right node
			   if(temnode->trightchild==NULL)
			      {
				  temnode->trightchild=newnode;
			      return;
			      }
			   else
			{
				  temnode=temnode->trightchild;//相当于递归。。。。 
			}
			
			if(newnode->num<temnode->num)//left node
			   if(temnode->tleftchild==NULL)
			   {
			   temnode->tleftchild=newnode;
			   return;//注意，当将一个节点添加到树上后一定要进行return，不然程序会陷入死循环。 
	        	}
			   else
			   {
			   	temnode=temnode->tleftchild;
			   }
		 } 
	}
 
 
 }

 void tree::preOrder(treenode *pertreeroot)    //前序遍历二叉树
 {   
     treenode *perorder =pertreeroot;
     
     if(perorder!=NULL)
     {
	 
	 
	     cout<<perorder->num<<endl;
	     preOrder(perorder->tleftchild);
	     preOrder(perorder->trightchild);
	 }
     	
 }
 
 void tree::inOrder(  treenode *intreeroot )
 {
 	 treenode *inorder =intreeroot;
     
     if(inorder!=NULL)
     {
	 
	 
	     copyinorder=inorder;//这是为了寻找左子树的最右端而设置的，为了解决节点删除的第三种情况 
	     inOrder(inorder->tleftchild);
		 cout<<inorder->num<<" "<<endl;
	     inOrder(inorder->trightchild);
	     
	 }
 	
 	
 }
 
 
 void tree::postOrder(treenode * postreeroot)
 {
 	 treenode *postorder =postreeroot;
     
     if(postorder!=NULL)
     {
	 
	 
	     
	     preOrder(postorder->tleftchild);
	     preOrder(postorder->trightchild);
		 cout<<postorder->num<<" "<<endl;
	 }
 	
 	
 }
 
 void tree::breadthFirstSearch(treenode* treeroot)
 {
 
 	queue<treenode*> qutree;//建立一个队列
	 qutree.push(treeroot);//将根节点压入队列
	 treenode *node;
	 while(!qutree.empty())
	 {
	 	
	 	node=qutree.front();
	 
	 	
	 
	 	qutree.pop();
	 		
		cout<<node->num<<endl;///z\z\这里有错误？？？？ 
	
	 	
	 	if(node->tleftchild)
	 	{
		 
		 qutree.push(treeroot->tleftchild);
		 
	    }
	 	if(node->trightchild)
	 	{
		 
		 qutree.push(treeroot->trightchild); 
		 
	    }
	 	
	 	//这里出现了一个！qutree.empty永远为真的循环 ，然后又莫名其妙的好了？？？？？？？、？？、 
	 	//system("pause");
	  } 
 	
 }
 
 
  void tree::deepthFirstSearch(treenode* treeroot)//根据堆栈的特性，先压入right再压left这样top就是left继续进行迭代 ,由于堆栈以及队列的插入，读取的不同导致了其功能的不同 
  {
  	stack<treenode*> stacktree;
	  stacktree.push(treeroot);
	  treenode *node;
	  while(!stacktree.empty())
	  {
	  	node=stacktree.top();//第一次是将root读出，第二次是rootleft、。。
		  
		  stacktree.pop();
		  cout<<node->num<<endl;
	
		  if(node->trightchild)//zhan的话要先push右边，后push左边，这样top就是先左边后右边，就可以对左边元素进行先行读出 
		     stacktree.push(node->trightchild);
		  if(node->tleftchild)
		     stacktree.push(node->tleftchild);
	  	
	   } 
  	
  	
  	
  	
  	
  }
 
 
  treenode *tree::Find(treenode* treeroot,int data)//二叉树的查找 ,类似于二分法 
 
 {
 	treenode * findroot= treeroot; 
  
 	while(findroot)
 	{
	 
	 if(findroot->num==data)
	    return findroot; 
 	
 	  else if(data<findroot->num)
	           {
				   findfathernode=findroot;		//为了在删除时得到删除节点的父节点而进行设置 
 	               findroot=findroot->tleftchild;
 	           }
 	  else if(data>findroot->num)
 	           
				{
				 findfathernode=findroot; 
 	             findroot=findroot->trightchild;
 	             } 
 	
    }
    return NULL;
 } 
 
 
 
  void tree::Insert(treenode* treeroot,int data) //二叉树的插入，比较元素大小，定位节点位置，判断节点周围成员，增加节点，貌似插入直接就是再树叶上插入，而不是类似链表可以任意插入 
  {
  	
  	
  	treenode *insertnode= new treenode; //用比较法来定位插入节点的位置 
  	insertnode->num=data;
	 insertnode->tleftchild=NULL;
	 insertnode->trightchild=NULL; 
	 treenode *copynode=treeroot;
	
  	treenode *newnode=treeroot;
  	
  	
  	cout<<"test1"<<endl;
  	
      while(newnode)       
	  {
	  	copynode=newnode;//因为到叶子节点后下一个指向空，所以需要拷贝节点将叶子节点进行保存 
	  	 cout<<"test2"<<endl;
	  	if(newnode->num<data)
		 {
		   newnode=newnode->trightchild;
		 cout<<"test3"<<endl;
	     }
	  	else if(newnode->num>data)
		 {
		   newnode=newnode->tleftchild;
	  	  cout<<"test4"<<endl;
	     }
	  }           
	 
  	cout<<copynode->num<<endl; 
	    
  if(data>copynode->num)
    copynode->trightchild=insertnode;
    else
    copynode->tleftchild=insertnode;
  
  
  	
  	
   } 
   
   
   void tree::Delete(treenode* treeroot,int data)//二叉树的删除需要考虑三种情况，第一：需要删除的是叶子节点，直接删除即可，第二，需要删除的节点有一个子节点，
   //类似链表进行删除中间节点即可，第三，删除的节点有左右两个子节点，我们将该节点左子树的最右节点进行定位后替代该节点，然后将最右节点删除。
   //1找到该节点位置，2判断是否有左右子节点3，根据情况进行删除 
{
   	
   treenode *deletenum=new treenode;
   deletenum=Find(treeroot,data);
   cout<<"delete num:"<<deletenum->num<<"'father num"<<findfathernode->num<<endl;
   if((deletenum->tleftchild==NULL)&&(deletenum->trightchild==NULL))//需要删除的节点为叶子节点 ，没有左右子节点 
       
   {
   	cout<<"test111"<<endl;
   	  if(findfathernode->num<deletenum->num)//右子节点指向空 ,,
   	           {cout<<"test222"<<endl;
				  findfathernode->trightchild=NULL;
				  delete  deletenum; 
			}
   	  else
		 {
		 	findfathernode->tleftchild=NULL; 
		 	 delete  deletenum; 
		 } 
   	
   } //这样做打印出来好像并没有对树进行删除， //这样是否将 
   
    else if((deletenum->tleftchild!=NULL)&&(deletenum->tleftchild!=NULL) )//需要删除的节点，有左和右儿子节点，第三种情况 
	 
      {
      	  //1,找出需删除节点的左子树的最右，是我们所定义的copyinorder，在inorder中已被 找见 ///逻辑有错误 
			//2将copyinoeder覆盖deletenum点 
			 deletenum->num=copyinorder->num;
			 //3，将 copyinorder 节点删除 
      	Delete(copyinorder,copyinorder->num); 
      	 delete  deletenum; 
      	
      }   
   else//两个儿子节点只有一个 
   
   {
   	 if(findfathernode->num<deletenum->num)//该节点为父节点的右儿子 
   	    {
		
     	if(deletenum->tleftchild!=NULL)//该节点的
		 findfathernode->trightchild=deletenum->tleftchild;
		 else
		  findfathernode->trightchild=deletenum->trightchild;
		   delete  deletenum; 
        }
   	else
   	    {
   		if(deletenum->tleftchild!=NULL)//该节点的
		 findfathernode->tleftchild=deletenum->tleftchild;
		 else
		  findfathernode->tleftchild=deletenum->trightchild;
		   delete  deletenum; 
        }
   		
   }
   	
   	
 }
    
   
   
   
   
    
   
 
 
 int main()
 {   treenode *returnfind=NULL;
     tree tree1;//在开始 时 tree tree（2）； tree tree1想用tree1作为一个对象来调用成员函数，但结果显示行不通，不知道是为什么，，持续关注该问题。。。。 
     
     
     int num=0,i=0,treenum=0,findnum=0,deletenum=0;
     cout<<"输入树的总结点个数"<<endl;
	 cin>>num; 
	 for(i=0;i<num;i++) 
	 {
	 	cout<<"输入树节点的值"<<endl;
	 cin>>treenum;
	
	 	tree1.creattree(treenum);
	 }
    //tree1.testtree(tree1.returnroot());
  // tree1.preOrder(tree1.returnroot());
    cout<<" "<<endl;
    tree1.inOrder(tree1.returnroot());
      cout<<" "<<tree1.copyinorder->num <<endl;
    //tree1.postOrder(tree1.returnroot());
      cout<<" "<<endl;
  // tree1.breadthFirstSearch(tree1.returnroot());
  //tree1.Insert(tree1.returnroot(),4);
  //tree1.deepthFirstSearch(tree1.returnroot());
   
  #if 0 
 cout<<"输入需要查找的节点："<<endl; 
  cin>>findnum;
   returnfind=tree1.Find(tree1.returnroot(),findnum);
  cout<<"find num:"<< returnfind->num<<endl;
  cout<<"find father num"<< tree1.findfathernode->num<<endl;
  # endif
  cout<<"输入需要删除的节点："<<endl; 
  cin>>deletenum;
  tree1.Delete(tree1.returnroot(),deletenum);
  cout<<"test444"<<endl;
   
  //cout<<"测试父节点是否为链表："<< tree1.findfathernode->trightchild->num<<endl;
  
  tree1.inOrder(tree1.returnroot());
  
   
 	 //c++中private只能由类成员函数访问 
 	
 }
