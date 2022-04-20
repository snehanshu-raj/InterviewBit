#include<bits/stdc++.h>
using namespace std;

struct node
{
	string name;
	vector <struct node*> children;
	int locked_desc_count = 0;
	bool is_locked = 0;
	int locked_by = -1;
	struct node* parent = NULL;
};

map <string, struct node*> refer;

bool can_be_locked_unlocked(string name)
{
	struct node* cur = refer[name];
		
	if(cur -> locked_desc_count > 0)
		return 0;
	
	cur = cur -> parent;
	while(cur)
	{
		if(cur -> is_locked == 1)
			return 0;
		cur = cur -> parent;
	}
	
	return 1;
}

bool lock(string name, int id)
{
	struct node* cur = refer[name];
	
	if(cur -> is_locked == 1)
		return 0;
		
	if( can_be_locked_unlocked(name) )
	{
		cur -> is_locked = 1;
		cur -> locked_by = id;
		
		cur = cur -> parent;
		while(cur)
		{
			cur -> locked_desc_count += 1;
			cur = cur -> parent;
		}
		
		return 1;
	}
	
	return 0;
}

bool unlock(string name, int id)
{
	struct node* cur = refer[name];
	if( can_be_locked_unlocked(name) )
	{
		if(cur -> locked_by == id)
		{
			cur -> is_locked = 0;
			cur -> locked_by = -1;
			
			cur = cur -> parent;
			while(cur)
			{
				cur -> locked_desc_count -= 1;
				cur = cur -> parent; 
			}
			
			return 1;
		}
		
		return 0;
	}
	
	return 0;
}

void level_order(struct node* root)
{
	queue <struct node*> q;
	q.push(root);
	
	cout << endl;
	while(!q.empty())
	{
		int level = q.size();
		while(level--)
		{
			struct node* temp = q.front();
			q.pop();
			
			cout << temp -> name << " ";
			
			for(int i = 0; i < temp -> children.size(); i++)
			{
				q.push(temp -> children[i]);
			}
		}
		
		cout << endl;
	}
}

int main()
{
	int total_nodes;
	int children_per_node;
	int queries;
	
	cin >> total_nodes >> children_per_node >> queries;
	
	int i;
	vector <string> nodes;
	for(i = 0; i < total_nodes; i++)
	{
		string val;
		cin >> val;
		
		nodes.push_back(val);
		
		struct node* temp = new node();
		temp -> name = val;
		
		refer[val] = temp;
	}
	
	// tree construction
	for(i = 0; children_per_node*i + children_per_node < total_nodes; i++)
	{
		struct node* parent = refer[ nodes[i] ];
		
		for(int j = 1; j <= children_per_node; j++)
		{
			int index_child = children_per_node*i + j;
			struct node* child = refer[ nodes[index_child] ];
			
			child -> parent = parent;
			parent -> children.push_back(child);
		}
	}
	
	// tree formation checker
	level_order(refer[nodes[0]]);
	
	for(i = 0; i < queries; i++)
	{
		int op, id;
		string names;
		
		cin >> op;
		cin >> names;
		cin >> id;
		
		if(op == 1)
			cout << lock(names, id) << endl;
		else
		if(op == 2)
			cout << unlock(names, id) << endl;
	}
	
return 0;
}
