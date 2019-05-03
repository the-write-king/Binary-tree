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
 		treenode *copyinorder; //�������������ֱ���ҵ������������ҽڵ� 
 		treenode* findfathernode;//�ڽڵ�ɾ��ʱ��Ҫ�õ��ýڵ�ĸ��ڵ㣬���Ҫ�Ըýڵ�ĸ��ڵ���в��Ҽ�¼ 
 		tree();//���캯�������ﲻ�ý�����г�ʼ������ creattree��������Ĵ��� 
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
		 void preOrder(treenode * );    //ǰ�����������
	
         void inOrder(treenode * );        //�������������
         void postOrder(treenode * );    //�������������
         treenode* Find(treenode* treeroot,int data);//�������Ĳ��� ,�ɹ��򷵻ظ�ָ�룬���򷵻�NULL 
		 void Insert(treenode* treeroot,int data);//�������Ĳ��� 
		 void Delete(treenode* treeroot,int data);//��������ɾ��
		  
         void breadthFirstSearch(treenode* treeroot);//��������㷨���ֽ�����α��� 
         void deepthFirstSearch(treenode* treeroot);//������� 
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
 

 int tree::treenodenum()//�����Ҫ����ϰ��vector��iterator��ʹ�ã��������� 
 {
     int maxnodenum;
 	cout<<"�����ܽڵ����"<<endl;
	  
	 cin>>maxnodenum;//�������endl���ֻ���ִ��󣬲�̫��������������������� 
	  
 	vector<int> treenum(maxnodenum,0);
 	vector<int>::iterator ptree;
 	
 	for(ptree=treenum.begin();ptree!=treenum.end();ptree++)
 	{
	 
	 cout<<"inter num"<<endl;
	 cin>>*ptree;//cin>>*ptree>>endl;�ᷢ�����󡣡����� 
	 
    }
 	for(ptree=treenum.begin();ptree!=treenum.end();ptree++)
 	cout<<"inter num\n"<<*ptree<<endl;
 	
 	return maxnodenum;
 }
 
 
 
 void tree::creattree(int val)//�������Ľ��� ���õݹ����ʵ�ֶ��������������� < ���ڵ� < �Ҷ��ӡ� 
 {
 
   treenode *newnode =new treenode;
   newnode->num=val;
   newnode->tleftchild=NULL;
   newnode->trightchild=NULL;
   //cout<<"addr"<< <<endl;//���treeroot�� ��ֵַΪ0x400000�������Ǵ�ͳ�����ϵ�NULL ,����ǵ�Ҫ��treeroot��ʼ�� ����ֹ��ָ��ָ�򲻿ɷ��ʵĵ�ַ 
   
   if(!treeroot)//����ʹ�ã�!ptr����ptr�� ֮���д��������д���ڶ���ƽ̨�϶�û���壬ֻ��һ��ͳһ�Ľ���� �Ӵ˿����ܽ�����ڲ�ͬ��ƽ̨�ϣ�NULL���ܻᱻ����Ϊ������ַ����Ȼ�����ַ���ǷǷ����ɷ��ʵġ�
    {	
    	treeroot= newnode; 
    	
	}
	else
	{
		treenode *temnode=new treenode;//����һ����ʱ�ĸ��ڵ㣬�Ժ�ûһ���ڵ�����ʱ��Ҫ�Ӹ��ڵ㿪ʼ�ж�
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
				  temnode=temnode->trightchild;//�൱�ڵݹ顣������ 
			}
			
			if(newnode->num<temnode->num)//left node
			   if(temnode->tleftchild==NULL)
			   {
			   temnode->tleftchild=newnode;
			   return;//ע�⣬����һ���ڵ���ӵ����Ϻ�һ��Ҫ����return����Ȼ�����������ѭ���� 
	        	}
			   else
			   {
			   	temnode=temnode->tleftchild;
			   }
		 } 
	}
 
 
 }

 void tree::preOrder(treenode *pertreeroot)    //ǰ�����������
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
	 
	 
	     copyinorder=inorder;//����Ϊ��Ѱ�������������Ҷ˶����õģ�Ϊ�˽���ڵ�ɾ���ĵ�������� 
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
 
 	queue<treenode*> qutree;//����һ������
	 qutree.push(treeroot);//�����ڵ�ѹ�����
	 treenode *node;
	 while(!qutree.empty())
	 {
	 	
	 	node=qutree.front();
	 
	 	
	 
	 	qutree.pop();
	 		
		cout<<node->num<<endl;///z\z\�����д��󣿣����� 
	
	 	
	 	if(node->tleftchild)
	 	{
		 
		 qutree.push(treeroot->tleftchild);
		 
	    }
	 	if(node->trightchild)
	 	{
		 
		 qutree.push(treeroot->trightchild); 
		 
	    }
	 	
	 	//���������һ����qutree.empty��ԶΪ���ѭ�� ��Ȼ����Ī������ĺ��ˣ��������������������� 
	 	//system("pause");
	  } 
 	
 }
 
 
  void tree::deepthFirstSearch(treenode* treeroot)//���ݶ�ջ�����ԣ���ѹ��right��ѹleft����top����left�������е��� ,���ڶ�ջ�Լ����еĲ��룬��ȡ�Ĳ�ͬ�������书�ܵĲ�ͬ 
  {
  	stack<treenode*> stacktree;
	  stacktree.push(treeroot);
	  treenode *node;
	  while(!stacktree.empty())
	  {
	  	node=stacktree.top();//��һ���ǽ�root�������ڶ�����rootleft������
		  
		  stacktree.pop();
		  cout<<node->num<<endl;
	
		  if(node->trightchild)//zhan�Ļ�Ҫ��push�ұߣ���push��ߣ�����top��������ߺ��ұߣ��Ϳ��Զ����Ԫ�ؽ������ж��� 
		     stacktree.push(node->trightchild);
		  if(node->tleftchild)
		     stacktree.push(node->tleftchild);
	  	
	   } 
  	
  	
  	
  	
  	
  }
 
 
  treenode *tree::Find(treenode* treeroot,int data)//�������Ĳ��� ,�����ڶ��ַ� 
 
 {
 	treenode * findroot= treeroot; 
  
 	while(findroot)
 	{
	 
	 if(findroot->num==data)
	    return findroot; 
 	
 	  else if(data<findroot->num)
	           {
				   findfathernode=findroot;		//Ϊ����ɾ��ʱ�õ�ɾ���ڵ�ĸ��ڵ���������� 
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
 
 
 
  void tree::Insert(treenode* treeroot,int data) //�������Ĳ��룬�Ƚ�Ԫ�ش�С����λ�ڵ�λ�ã��жϽڵ���Χ��Ա�����ӽڵ㣬ò�Ʋ���ֱ�Ӿ�������Ҷ�ϲ��룬������������������������ 
  {
  	
  	
  	treenode *insertnode= new treenode; //�ñȽϷ�����λ����ڵ��λ�� 
  	insertnode->num=data;
	 insertnode->tleftchild=NULL;
	 insertnode->trightchild=NULL; 
	 treenode *copynode=treeroot;
	
  	treenode *newnode=treeroot;
  	
  	
  	cout<<"test1"<<endl;
  	
      while(newnode)       
	  {
	  	copynode=newnode;//��Ϊ��Ҷ�ӽڵ����һ��ָ��գ�������Ҫ�����ڵ㽫Ҷ�ӽڵ���б��� 
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
   
   
   void tree::Delete(treenode* treeroot,int data)//��������ɾ����Ҫ���������������һ����Ҫɾ������Ҷ�ӽڵ㣬ֱ��ɾ�����ɣ��ڶ�����Ҫɾ���Ľڵ���һ���ӽڵ㣬
   //�����������ɾ���м�ڵ㼴�ɣ�������ɾ���Ľڵ������������ӽڵ㣬���ǽ��ýڵ������������ҽڵ���ж�λ������ýڵ㣬Ȼ�����ҽڵ�ɾ����
   //1�ҵ��ýڵ�λ�ã�2�ж��Ƿ��������ӽڵ�3�������������ɾ�� 
{
   	
   treenode *deletenum=new treenode;
   deletenum=Find(treeroot,data);
   cout<<"delete num:"<<deletenum->num<<"'father num"<<findfathernode->num<<endl;
   if((deletenum->tleftchild==NULL)&&(deletenum->trightchild==NULL))//��Ҫɾ���Ľڵ�ΪҶ�ӽڵ� ��û�������ӽڵ� 
       
   {
   	cout<<"test111"<<endl;
   	  if(findfathernode->num<deletenum->num)//���ӽڵ�ָ��� ,,
   	           {cout<<"test222"<<endl;
				  findfathernode->trightchild=NULL;
				  delete  deletenum; 
			}
   	  else
		 {
		 	findfathernode->tleftchild=NULL; 
		 	 delete  deletenum; 
		 } 
   	
   } //��������ӡ��������û�ж�������ɾ���� //�����Ƿ� 
   
    else if((deletenum->tleftchild!=NULL)&&(deletenum->tleftchild!=NULL) )//��Ҫɾ���Ľڵ㣬������Ҷ��ӽڵ㣬��������� 
	 
      {
      	  //1,�ҳ���ɾ���ڵ�������������ң��������������copyinorder����inorder���ѱ� �Ҽ� ///�߼��д��� 
			//2��copyinoeder����deletenum�� 
			 deletenum->num=copyinorder->num;
			 //3���� copyinorder �ڵ�ɾ�� 
      	Delete(copyinorder,copyinorder->num); 
      	 delete  deletenum; 
      	
      }   
   else//�������ӽڵ�ֻ��һ�� 
   
   {
   	 if(findfathernode->num<deletenum->num)//�ýڵ�Ϊ���ڵ���Ҷ��� 
   	    {
		
     	if(deletenum->tleftchild!=NULL)//�ýڵ��
		 findfathernode->trightchild=deletenum->tleftchild;
		 else
		  findfathernode->trightchild=deletenum->trightchild;
		   delete  deletenum; 
        }
   	else
   	    {
   		if(deletenum->tleftchild!=NULL)//�ýڵ��
		 findfathernode->tleftchild=deletenum->tleftchild;
		 else
		  findfathernode->tleftchild=deletenum->trightchild;
		   delete  deletenum; 
        }
   		
   }
   	
   	
 }
    
   
   
   
   
    
   
 
 
 int main()
 {   treenode *returnfind=NULL;
     tree tree1;//�ڿ�ʼ ʱ tree tree��2���� tree tree1����tree1��Ϊһ�����������ó�Ա�������������ʾ�в�ͨ����֪����Ϊʲô����������ע�����⡣������ 
     
     
     int num=0,i=0,treenum=0,findnum=0,deletenum=0;
     cout<<"���������ܽ�����"<<endl;
	 cin>>num; 
	 for(i=0;i<num;i++) 
	 {
	 	cout<<"�������ڵ��ֵ"<<endl;
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
 cout<<"������Ҫ���ҵĽڵ㣺"<<endl; 
  cin>>findnum;
   returnfind=tree1.Find(tree1.returnroot(),findnum);
  cout<<"find num:"<< returnfind->num<<endl;
  cout<<"find father num"<< tree1.findfathernode->num<<endl;
  # endif
  cout<<"������Ҫɾ���Ľڵ㣺"<<endl; 
  cin>>deletenum;
  tree1.Delete(tree1.returnroot(),deletenum);
  cout<<"test444"<<endl;
   
  //cout<<"���Ը��ڵ��Ƿ�Ϊ����"<< tree1.findfathernode->trightchild->num<<endl;
  
  tree1.inOrder(tree1.returnroot());
  
   
 	 //c++��privateֻ�������Ա�������� 
 	
 }
