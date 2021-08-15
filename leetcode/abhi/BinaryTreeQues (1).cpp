/*
 * index::
 * Q1)postorder successor
 * Q2)inorder successor
 * Q3)convert expression to binary tree 
 * Q4)LCA of 2 nodes 
 * Q5)Diameter of tree 
 * Q6)Path Sum
 * Q7)Validate Binary Search Trees
 * Q8)Same Tree :: Given 2 tree nodes tell if they are structurally equal
 * Q9)Delete Leaf Nodes with given target values
 * Q10)Maximum path sum ( FEEL OF DP )
 * Q11)Kth Smallest element in bst
 * Q12)Symmetric Tree
 * Q13)Mirror Tree
 * Q14)Ceil of bst
 * Q15)Floor of bst
 * Q16)Check if the tree is height balanced
 *
 * Q17)MinDepth of binary tree
 * Q18)MaxDepth of binary tree
 *
 * Traversals::
 * Q19)Inorder Traversal
 * Q20)Preorder Traversal
 * Q21)Postorder Traversal
 * Q22)Level Order Traversal
 * Q23)Spiral Order Traversal
 * Q231)Diagonal Order Traversal
 *
 * Views
 *
 * Q24)Left View
 * Q25)Right View
 * Q26)Top View
 * Q27)Bottom View
 *
 * Q28)Merge 2 Binary Trees
 * Q29)Subtree of Another Tree
 * Q30)Count subtrees that sum up to a given value x using single recursive function
 * Q31)Size of largest bst in a bt
 * Q32)Remove all the nodes which lie outside the given range
 * Q33)Second Largest Element in the BST
 * Q34)Convert Binary tree to its mirror tree
 * Q35)Flatten a binary tree to linked list
 *
 * Q36) Construct Binary tree from inorder and preorder traversal
 * Q37) Construct Binary tree from inorder and postorder traversal
 *
 * Q38)Binary Tree Longest Consecutive Path
 */

//Q1)postorder successor
node * postorder_successor(node * root , node * g){
    if(g == root)
        return NULL;
    //if g is the right node of its parent or the left node of the parent is NULL then parent is the postorder successor
    if(!g -> parent -> left || g -> parent -> right == g)
        return g;

    //if g is the left node of the parent then ans is the leftmost node of the right subtree
    node * cur = g -> parent -> left;
    while(!cur -> left){
        cur = cur -> left;
    }
    return cur;
}

//Q2)inorder successor
node * inorder_successor(node * root , node * g){
    if(g -> right){
        //if right subtree exist , ans is minimum of the right subtree
        node * cur = g -> right;
        while(!cur -> left)
            cur = cur -> left;
        return cur;
    }
  
    //travel up untill the node becomes the left child of its parent
    node * cur = g;
    while(g -> parent && g -> parent -> left != g)
        g = g -> parent;
    return g -> parent;
}


//Q3)convert expression to binary tree , 
//input :: a?b?c:d:e
//output    
/*          a
           /  \
          b    e
        /  \
       c    d
*/
node * fun(const string & str , int & i){
    node * head = new node(str[i]);
    i++;
    if(str.size() == i)
        return head;
    if(str[i] == '?'){
        i++;
        head -> left = fun(str , i);
        head -> right = fun(str , i);
    }else{
        i++;
    }
    return head;
}

//Q4)LCA of 2 nodes
int ans = -1;
#define f first
#define s second
pair<int,int> fun(Tree * root , int a , int b){
    if(!root){
        return {0 , 0};
    }
    auto left = fun(root -> left , a , b);
    auto right = fun(root -> right , a , b);
    if(ans != -1)
        return {0 , 0};
    int l = left.f || right.f || root -> val == a;
    int r = left.s || right.s || root -> val == b;
    if((left.f || right.f || root -> val == a) && (left.s || right.s || root -> val == b)){
        ans = root -> val;
        return {0 , 0};
    }
    return {l , r};
}
int solve(Tree* root, int a, int b) {
    // Write your code here
    fun(root , a , b);
    return ans;
}



//Q5)diameter of tree :: max no. of edges bw 2 nodes in binary tree
int ans = 0;
void fun(node * root){
    if(!root)
        return 0;
    int max_l = root -> left ? 1 + fun(root -> left) : 0;
    int max_r = root -> right ? 1 + fun(root -> right) : 0;
    ans = max({max_l + max_r , ans , maxl , maxr});
    return max(max_l , max_r);
}

//Q6)Path Sum :: Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
bool fun(TreeNode * root , int sum){
    if(!root)
        return false;
    if(root -> left && root -> right){
        bool res = false;
        res |= fun(root -> left , sum - root -> val);
        res |= fun(root -> right , sum - root -> val);
        return res;
    }else if(root -> left)
        return fun(root -> left , sum - root -> val);
    else if(root -> right)
        return fun(root -> right , sum - root -> val);
    else
        return root -> val == sum;
}

//Q7)Validate Binary Search Trees
bool isValidBST(TreeNode * root , long long l = INT_MIN , long long r = INT_MAX){
    if(!root)
        return 1;
    return  isValidBST(root -> left , l , root -> val*1LL - 1) && 
            isValidBST(root -> right , root -> val *1LL + 1 , r) && 
            (root -> val >= l && root -> val <= r);
}

//Q8)Same Tree :: Given 2 tree nodes tell if they are structurally equal
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p and !q)
        return 1;
    if(!p || !q)
        return 0;
    return (p->val == q->val) && isSameTree(p->left , q->left) && isSameTree(p->right , q-> right);
}

//Q9)delete leaf nodes with given target values
TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if(!root -> left and !root -> right){
        if(root -> val == target){
            return NULL;
        }
        return root;
    }
    if(root -> left)
        root -> left = removeLeafNodes(root -> left , target);
    if(root -> right)
        root -> right = removeLeafNodes(root -> right , target);
    if(!root -> left and !root -> right && root -> val == target) // maybe after deletion of leaves the current node has become leaf ? 
        return NULL;
    return root;
}

//Q10)Maximum path sum in a binary tree
int ans = 0;
int fun(TreeNode * root){
    if(!root)
        return 0;
    int l = fun(root -> left);
    int r = fun(root -> right);
    ans = max({ans , l + r + root -> val , r + root -> val , l + root -> val});
    return max(0 , max(l , r)) + root -> val;
}
int maxPathSum(TreeNode* root) {
    ans = root ? root -> val : 0;
    fun(root);        
    return ans;
}

//Q11)Kth smallest element in bst
int kthSmallest(TreeNode* root, int & k) {
    int ans = -1;
    if(root -> left)
        ans = kthSmallest(root -> left , k);

    if(ans != -1)
        return ans;

    k--;
    if(k == 0)
        return root->val;

    if(root -> right)
        ans = kthSmallest(root -> right , k);
    return ans;

}

//Q12)Symmetric tree problem :: Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
bool isSymmetric(TreeNode * root) {
    return isMirror(root, root);
}

//Q13)Mirror Tree
bool isMirror(TreeNode * t1, TreeNode * t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;
    return (t1 -> val == t2 -> val)
        && isMirror(t1 -> right , t2 -> left)
        && isMirror(t1 -> left , t2 -> right);
}

//Q14)Ceil of a bst
int Ceil(node* root, int input) { 
    // Base case 
    if (root == NULL) 
        return -1; 
  
    // We found equal key 
    if (root->key == input) 
        return root->key; 

    // If root's key is smaller, ceil must be in right subtree 
    if (root->key < input) 
        return Ceil(root->right, input); 
  
    // Else, either left subtree or root has the ceil value 
    int ceil = Ceil(root->left, input); 
    return (ceil >= input) ? ceil : root->key; 
} 

//Q15)Floor of a bst
int floor(Node* root, int key) { 
    if (!root) 
        return INT_MAX; 
  
    /* If root->data is equal to key */
    if (root->data == key) 
        return root->data; 
  
    /* If root->data is greater than the key */
    if (root->data > key) 
        return floor(root->left, key); 
  
    /* Else, the floor may lie in right subtree 
      or may be equal to the root*/
    int floorValue = floor(root->right, key); 
    return (floorValue <= key) ? floorValue : root->data; 
} 

//Q16)Check if BST is height balanced.
bool ok;
int fun(TreeNode * root){
    if(!root)
        return 0;
    int l = fun(root -> left);
    int r = fun(root -> right);
    if(abs(r - l) > 1)
        ok &= 0;
    return max(l , r) + 1;
}

bool isBalanced(TreeNode* root) {
    ok = 1;
    fun(root);
    return ok;
}

//Q17) Min Depth of binary tree
int minDepth(TreeNode* root) {
    if(!root)
        return 0;
    if(root->left && root->right)
        return min(minDepth(root->left) , minDepth(root->right)) + 1;
    if(root->left)
        return 1 + minDepth(root->left);
    if(root->right)
        return 1 + minDepth(root->right);
    return 1;
}

//Q18) Max Depth of binary tree
int maxDepth(TreeNode* root) {
    if(!root)
        return 0;
    return 1 + max(maxDepth(root->left) , maxDepth(root->right));
}

//Q19)Post Order Traversal
void post_order(node * root){
    if(root){
        post_order(root->left);
        post_order(root->right);
        cout << root->val << ' ' ;
    }
}

public List<Integer> postorderTraversal(TreeNode root) {
    LinkedList<Integer> result = new LinkedList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while(!stack.isEmpty() || p != null) {
        if(p != null) {
            stack.push(p);
            result.addFirst(p.val);  // Reverse the process of preorder
            p = p.right;             // Reverse the process of preorder
        } else {
            TreeNode node = stack.pop();
            p = node.left;           // Reverse the process of preorder
        }
    }
    return result;
}



//Q20)In Order Traversal
void in_order(node * root){
    if(root){
        in_order(root->left);
        cout << root->val << ' ';
        in_order(root->right);
    }
}

public List<Integer> inorderTraversal(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while(!stack.isEmpty() || p != null) {
        if(p != null) {
            stack.push(p);
            p = p.left;
        } else {
            TreeNode node = stack.pop();
            result.add(node.val);  // Add after all left children
            p = node.right;   
        }
    }
    return result;
}


//Q21)Pre Order Traversal
public List<Integer> preorderTraversal(TreeNode root) {
    List<Integer> result = new ArrayList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode p = root;
    while(!stack.isEmpty() || p != null) {
        if(p != null) {
            stack.push(p);
            result.add(p.val);  // Add before going to children
            p = p.left;
        } else {
            TreeNode node = stack.pop();
            p = node.right;   
        }
    }
    return result;
}

//Q22)Level Order Traversal
void level_order(node * root){
    queue<node *> q;
    vector<int> ans;
    while(!q.empty()){
        auto t = q.front();
        ans.push_back(t->val);
        q.pop();
        if(t->left)
            q.push(t->left);
        if(t->right)
            q.push(t->right);
    }

    for(int i : ans) cout << i << " " ;
    cout << '\n';
}

//Q23)Spiral Order Traversal
void printSpiral(Node *root){
    //Your code here
    if(root == NULL)
        return;
    queue<pair<Node*, int>> q;
    q.push({root , 0});
    map<int,vector<int>> ans;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        ans[t.second].push_back(t.first -> data);
        if(t.first -> left)
            q.push({t.first -> left , t.second + 1});
        if(t.first -> right)
            q.push({t.first -> right , t.second + 1});
    }
    for(auto i : ans){
        int lvl = i.first;
        if(!(lvl & 1))
            reverse(i.second.begin() , i.second.end());
        
        for(int o : i.second) cout << o << ' ';
    }
}


//Q231)Diagonal Traversal of binary Tree
void diagonalPrintUtil(Node* root, int d, 
                      map<int, vector<int>> &diagonalPrint) 
{ 
    if (!root) 
        return; 
  
    // Store all nodes of same line together as a vector 
    diagonalPrint[d].push_back(root->data); 
  
    // Increase the vertical distance if left child 
    diagonalPrintUtil(root->left, d + 1, diagonalPrint); 
  
    // Vertical distance remains same for right child 
    diagonalPrintUtil(root->right, d, diagonalPrint); 
} 
  
// Print diagonal traversal of given binary tree 
void diagonalPrint(Node* root) 
{ 
    // create a map of vectors to store Diagonal elements 
    map<int, vector<int> > diagonalPrint; 
    diagonalPrintUtil(root, 0, diagonalPrint); 
  
    cout << "Diagonal Traversal of binary tree : n"; 
    for (auto it = diagonalPrint.begin(); 
         it != diagonalPrint.end(); ++it) 
    { 
        for (auto itr = it->second.begin(); 
             itr != it->second.end(); ++itr) 
            cout << *itr  << ' '; 
  
        cout << 'n'; 
    } 
} 



//Q24)Left View
vector<int> left_view(node * root){
    
    vector<int> ans;
    if(!root) return ans;

    queue<pair<node * , int>> q;
    q.push({root , 0});
    unordered_set<int> hs;

    while(!q.empty()){
        auto t = q.front();
        q.pop();
        
        if(!hs.count(t.s)){
            hs.insert(t.s);
            ans.push_back(t.f -> val);
        }
        
        if(t.f -> left)
            q.push({t.f -> left , 1 + t.s});

        if(t.f -> right)
            q.push({t.f -> right , 1 + t.s});
    }

    return ans;
}

//Q25)Right View
vector<int> right_view(node* root) {
    
    vector<int> ans;
    if(!root) return ans;

    queue<pair<node * , int>> q;
    q.push({root , 0});
    unordered_set<int> hs;

    while(!q.empty()){
        auto t = q.front();
        q.pop();
        
        if(!hs.count(t.s)){
            hs.insert(t.s);
            ans.push_back(t.f -> val);
        }
        
        if(t.f -> right)
            q.push({t.f -> right , 1 + t.s});

        if(t.f -> left)
            q.push({t.f -> left , 1 + t.s});
    }

    return ans; 
}

//Q26 Top View
vector<int> top_view(node * root){
    vector<int> ans;
    if(!root) return ans;

    queue<pair<node * , int>> q;
    q.push({root , 0});
    
    map<int , int> hm;
    
    hm[0] = root -> val;

    while(!q.empty()){
        auto t = q.front();
        q.pop();
    
        if(t.f -> left){
            if(!hm.count(t.s - 1))
                hm[t.s - 1] = t.f -> left -> val;
            q.push({t.f -> left , t.s - 1});
        }
    
        if(t.f -> right){
            if(!hm.count(t.s + 1))
                hm[t.s + 1] = t.f -> right -> val;
            q.push({t.f -> right , 1 + t.s});
        }

    }

    for(auto it : hm)
        ans.push_back(it.s);
    
    return ans;
}

//Q27) Bottom View
vector<int> bottom_view(node * root){
    vector<int> ans;
    if(!root) return ans;

    queue<pair<node * , int>> q;
    q.push({root , 0});
    
    map<int , int> hm;
    
    hm[0] = root -> val;

    while(!q.empty()){
        auto t = q.front();
        q.pop();
        
        if(t.f -> left){
            hm[t.s - 1] = t.f -> left -> val;
            q.push({t.f -> left , t.s - 1});
        } 
        
        if(t.f -> right){
            hm[t.s + 1] = t.f -> right -> val;
            q.push({t.f -> right , 1 + t.s});
        }

    }

    for(auto it : hm)
        ans.push_back(it.s);
    
    return ans;
}

//Q28)Merge 2 binary trees
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    
    if(!t2)
        return t1;
    if(!t1){
        TreeNode * t = new TreeNode(t2 -> val);
        t -> left = mergeTrees(t1 , t2 -> left);
        t -> right = mergeTrees(t1 , t2 -> right);
        return t;
    }
    
    t1 -> val += t2 -> val;
    t1 -> left = mergeTrees(t1 -> left , t2 -> left);
    t1 -> right = mergeTrees(t1 -> right , t2 -> right);
    return t1;
}

//Q29)Subtree if another tree
bool isSame(TreeNode * s , TreeNode * t){
    if(!s && !t)
        return true;
    if(!s || !t)
        return false;
    return s -> val == t -> val && isSame(s -> left , t -> left) && isSame(s -> right , t -> right);
}

bool isSubtree(TreeNode* s, TreeNode* t) {
    if(s && t)
        return isSame(s , t) || isSubtree(s -> left , t) || isSubtree(s -> right , t);
    return false;
}


//Q30)Count subtrees that sum up to a given value x only using single recursive function
//pair<int,int> stores {ans for the subtree , sum of the subtree}
pair<int,int> fun(Node * root , int x){
    if(!root)
        return make_pair(0 , 0);

    auto [ans_l , sum_l] = fun(root -> left , x);
    auto [ans_r , sum_r] = fun(root -> right , x);
    
    int sum = sum_l + sum_r + root -> data;
    
    pair<int,int> ans = {ans_l + ans_r + (sum == x) , sum};
    return ans;
}


//Q31)Size of largest bst in a bt
struct Info 
{ 
    int sz; // Size of subtree 
    int max; // Min value in subtree 
    int min; // Max value in subtree 
    int ans; // Size of largest BST which 
    // is subtree of current node 
    bool isBST; // If subtree is BST 
}; 
  
// Returns Information about subtree. The 
// Information also includes size of largest 
// subtree which is a BST. 
Info largestBSTBT(Node* root) 
{ 
    // Base cases : When tree is empty or it has 
    // one child. 
    if (root == NULL) 
        return {0, INT_MIN, INT_MAX, 0, true}; 
    if (root->left == NULL && root->right == NULL) 
        return {1, root->data, root->data, 1, true}; 
  
    // Recur for left subtree and right subtrees 
    Info l = largestBSTBT(root->left); 
    Info r = largestBSTBT(root->right); 
  
    // Create a return variable and initialize its 
    // size. 
    Info ret; 
    ret.sz = (1 + l.sz + r.sz); 
  
    // If whole tree rooted under current root is 
    // BST. 
    if (l.isBST && r.isBST && l.max < root->data && 
            r.min > root->data) 
    { 
        ret.min = min(l.min, min(r.min, root->data)); 
        ret.max = max(r.max, max(l.max, root->data)); 
  
        // Update answer for tree rooted under 
        // current 'root' 
        ret.ans = ret.sz; 
        ret.isBST = true; 
  
        return ret; 
    } 
  
    // If whole tree is not BST, return maximum 
    // of left and right subtrees 
    ret.ans = max(l.ans, r.ans); 
    ret.isBST = false; 
  
    return ret; 
} 



// Q32) Removes all nodes having value outside the given range and returns the root 
// of modified tree 
node* removeOutsideRange(node *root, int min, int max) 
{ 
   // Base Case 
   if (root == NULL) 
      return NULL; 
  
   // First fix the left and right subtrees of root 
   root->left =  removeOutsideRange(root->left, min, max); 
   root->right =  removeOutsideRange(root->right, min, max); 
  
   // Now fix the root.  There are 2 possible cases for toot 
   // 1.a) Root's key is smaller than min value (root is not in range) 
   if (root->key < min) 
   { 
       node *rChild = root->right; 
       delete root; 
       return rChild; 
   } 
   // 1.b) Root's key is greater than max value (root is not in range) 
   if (root->key > max) 
   { 
       node *lChild = root->left; 
       delete root; 
       return lChild; 
   } 
   // 2. Root is in range 
   return root; 
} 
  
//Q33)Find the second Largest Element in the BST
void secondLargestUtil(Node *root, int &c) 
{ 
    // Base cases, the second condition is important to 
    // avoid unnecessary recursive calls 
    if (root == NULL || c >= 2) 
        return; 
  
    // Follow reverse inorder traversal so that the 
    // largest element is visited first 
    secondLargestUtil(root->right, c); 
  
    // Increment count of visited nodes 
    c++; 
  
    // If c becomes k now, then this is the 2nd largest 
    if (c == 2) 
    { 
        cout << "2nd largest element is "
             << root->key << endl; 
        return; 
    } 
  
    // Recur for left subtree 
    secondLargestUtil(root->left, c); 
} 

//Q34)Convert a binary tree to its mirror tree
void fun(node * root){
    if(!root)
        return ;
    if(root -> left)
        fun(root -> left);
    if(root -> right)
        fun(root -> right);
    swap(root -> left , root -> right);
}

//Q35) Flatten a bst to a linked list
private TreeNode prev = null;

public void flatten(TreeNode root) {
    if (root == null)
        return;
    flatten(root.right);
    flatten(root.left);
    root.right = prev;
    root.left = null;
    prev = root;
}


//Q36) Construct Binary Tree from Preorder and Inorder Traversal
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return builTreeHelper(preorder,0,preorder.size(),inorder,0,inorder.size());
}

TreeNode* builTreeHelper(vector<int>& preorder, int sp, int ep, vector<int>& inorder, int si, int ei) {
    if (sp == ep) return nullptr;
    TreeNode* root = new TreeNode(preorder[sp]);
    int dis = find(inorder.begin()+si,inorder.begin()+ei,preorder[sp]) - inorder.begin() - si;
    root->left = builTreeHelper(preorder,sp+1,sp+1+dis,inorder,si,si+dis);
    root->right = builTreeHelper(preorder,sp+1+dis,ep,inorder,si+dis+1,ei);
    return root;
}


//Q37) Binary Tree Longest Consecutive Path
class Solution {
    public:
    int global_ans;
    pair<int,int> fun(Tree * root){
        if(!root)
            return {0 , 0};
        
        //li , ri stores the longest increasing path in the left subtree and right subtree
        //ld , rd stores the longest decreasing path in the left subtree and right subtree
        auto [li , ld] = fun(root -> left);
        auto [ri , rd] = fun(root -> right);
        
        int ans = 1;
        int inc = 1 , dec = 1;
        if(root -> left && root -> left -> val == root -> val + 1){
            inc = 1 + li;
            ans = max(ans , inc);
        }
            
        if(root -> left && root -> left -> val == root -> val - 1){
            dec = 1 + ld;
            ans = max(ans , dec);
        }
            
        if(root -> right && root -> right -> val == root -> val + 1){
            inc = max(inc , 1 + ri);
            ans = max(ans , inc);
        }
        
        if(root -> right && root -> right -> val == root -> val - 1){
            dec = max(dec , 1 + rd);
            ans = max(ans , dec);
        }
            
        if(root -> right && root -> left){
            if(root -> left -> val == root -> val + 1 && root -> right -> val == root -> val - 1)
                global_ans = max(global_ans , li + rd + 1);
            if(root -> left -> val == root -> val - 1 && root -> right -> val == root -> val + 1)
                global_ans = max(global_ans , ld + ri + 1);
        }
        
        global_ans = max({li , ri , ld , rd , global_ans , ans});
        return make_pair(inc , dec);
    }
    
    int solve(Tree* root) {
        global_ans = 0;
        // Write your code here
        fun(root);
        return global_ans;
    }
};
