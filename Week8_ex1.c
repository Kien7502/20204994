//Khoi tao ova kiem tra cay
typedef … elmType;
typedef struct nodeType {
	elmType element;
	struct nodeType *left, *right;
} node_Type;

typedef struct nodeType *treetype;
void MakeNullTree(treetype *T){ 
	(*T)=NULL; 
} 
int EmptyTree(treetype T){ 
	return T==NULL; 
}

//Truy cap con trai
treetype LeftChild(treetype n){ 
	if (n!=NULL) return n->left; 
	else return NULL;
}

//Truy cap con phai
treetype RightChild(treetype n){ 
	if (n!=NULL) return n->right;
	else return NULL;
}

//Tao nut moi
node_type *create_node(elmtype NewData){ 
	N=(node_type*)malloc(sizeof(node_type));
	if (N != NULL){ 
		N->left = NULL;
		N->right = NULL;
		N->element = NewData;
	}
	return N;
}

//Kiem tra co phai la la
int IsLeaf(treetype n){
	if(n!=NULL) 
		return(LeftChild(n)==NULL)&&(RightChild(n)==NULL); 
	else return -1; 
} 

//Tim so nut tren cay
int nb_nodes(treetype T){ 
	if(EmptyTree(T)) return 0; 
	else return 1+nb_nodes(LeftChild(T))+nb_nodes(RightChild(T)); 
}

//Tao mot cay tu hai cay con
treetype createfrom2(elmtype v, treetype l, treetype r){ 
	treetype N; 
	N=(node_type*)malloc(sizeof(node_type));
	N->element=v;
	N->left=l; 
	N->right=r;
	return N;
}

//Them nut vaoo vi tri trai nhat
treetype Add_Left(treetype *Tree, elmtype NewData){ 
	node_type *NewNode = Create_Node(NewData);
	if (NewNode == NULL) return (NewNode);
	if (*Tree == NULL)
		*Tree = NewNode;
	else{
		node_type *Lnode = *Tree;
		while (Lnode->left != NULL)
		Lnode = Lnode->left;
		Lnode->left = NewNode;
	}
	return (NewNode);
}

//Them nut vao vi tri phai nhat 
treetype Add_Right(treetype *Tree, elmtype NewData){ 
	node_type *NewNode = Create_Node(NewData);
	if (NewNode == NULL) return (NewNode);
	if (*Tree == NULL)
		*Tree = NewNode;
	else{
		node_type *Rnode = *Tree;
		while (Rnode->right != NULL)
		Rnode = Lnode->right;
		Rnode->right = NewNode;
	}
	return (NewNode);
}
