class Solution1{
    public:
    bool areAnagrams2(Node *root1, Node *root2){
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
        
    queue<Node *> q1, q2;
    q1.push(root1);
    q2.push(root2);
 
    while (1)
    {
        int n1 = q1.size(), n2 = q2.size();
        if (n1 != n2)
            return false;
        if (n1 == 0)
            break;
            
        vector<int> curr_level1, curr_level2;
        while (n1 > 0)
        {
            Node *node1 = q1.front();
            q1.pop();
            if (node1->left != NULL)
                q1.push(node1->left);
            if (node1->right != NULL)
                q1.push(node1->right);
            n1--;
 
            Node *node2 = q2.front();
            q2.pop();
            if (node2->left != NULL)
                q2.push(node2->left);
            if (node2->right != NULL)
                q2.push(node2->right);
 
            curr_level1.push_back(node1->data);
            curr_level2.push_back(node2->data);
        }

        sort(curr_level1.begin(), curr_level1.end());
        sort(curr_level2.begin(), curr_level2.end());
        if (curr_level1 != curr_level2)
            return false;
    }
 
    return true;
    }
};

//better
class Solution{
    public:
    bool areAnagrams(Node *root1, Node *root2)
    {
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
 
    // start level order traversal of two trees
    queue<Node*> q1, q2;
    q1.push(root1);
    q2.push(root2);
 
    // Hashmap to store the elements that occur in each level
    unordered_map<int, int> m;
 
    while (!q1.empty() && !q2.empty()) {
        int n1 = q1.size(), n2 = q2.size();
 
        if (n1 != n2)
            return false;
        if (n1 == 0)
            break;

        while (n1--) {
            Node* node1 = q1.front();
            q1.pop();
 
            m[node1->data]++;
 
            if (node1->left != NULL)
                q1.push(node1->left);
            if (node1->right != NULL)
                q1.push(node1->right);
        }
 
 
        while (n2--) {
            Node* node2 = q2.front();
            q2.pop();
 
            if (m.find(node2->data) == m.end())
                return false;
            m[node2->data]--;
            // If frequency of the element becomes zero then
            // remove the element from hashmap.
            if (m[node2->data] == 0)
                m.erase(node2->data);
                
            if (node2->left != NULL)
                q2.push(node2->left);
            if (node2->right != NULL)
                q2.push(node2->right);
        }
        if (m.size() > 0)
            return false;
    }
      if(q1.empty() && q2.empty())
        return true;
      return false;
    }
};
