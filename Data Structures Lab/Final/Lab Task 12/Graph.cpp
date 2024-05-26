#include<iostream>
#include<vector>
#include<iterator>
#include<list>

using namespace std;

class Edge{
    public:
        int DestinationVertexId;
        int Weight;

        Edge(){}

        Edge(int val1, int val2)
        {
            DestinationVertexId = val1;
            Weight = val2;
        }

        void Insert(int val1, int val2)
        {
            DestinationVertexId = val1;
            Weight = val2;
        }

        void ModifyWeight(int w)
        {
            Weight = w;
        }

        int GetDestinationVertex()
        {
            return DestinationVertexId;
        }

        int GetWeight()
        {
            return Weight;
        }
};

class Vertex{
    public:
        int id;
        string name;
        list<Edge> e;

        Vertex()
        {
            id = 0;
            name = "";
        }

        Vertex(int x, string y)
        {
            id = x;
            name = y;
        }

        void SetId(int x)
        {
            id = x;
        }

        void SetName(string n)
        {
            name = n;
        }

        int GetId()
        {
            return id;
        }

        string GetName()
        {
            return name;
        }

        list<Edge> GetEdgeList()
        {
            return e;
        }
};

class Graph{
    public:
        vector<Vertex> v;

        void AddVertex(Vertex obj)
        {
            bool Check = CheckIfVertexExistById(obj.GetId());
            if(Check == true)
            {
                cout << "Vertex already exist." << endl;
            }
            else
            {
                v.push_back(obj);
                cout << "Vertex added successfully. " << endl;
            }
        }

        bool CheckIfVertexExistById(int id)
        {
            bool flag = false;
            for(int i=0; i<v.size(); i++)
            {
                if(v.at(i).GetId() == id)
                {
                    return true;
                }
            }
            return flag;
        }

        Vertex GetVertexById(int id)
        {
            Vertex temp;
            for(int i=0; i<v.size(); i++)
            {
                temp = v.at(i);
                if(temp.GetId() == id)
                {
                    return temp;
                }
            }
            return temp;
        }

        bool CheckIfEdgeExistById(int fromVertex, int toVertex)
        {
            Vertex v = GetVertexById(fromVertex);
            list<Edge> e;
            e = v.GetEdgeList();
            for(auto i = e.begin(); i!=e.end(); i++)
            {
                if(i->GetDestinationVertex()==toVertex)
                {
                    return true;
                    break;
                }
            }
            return false;
        }

        void AddEdgeById(int fromVertex, int toVertex, int w)
        {
            bool Check1 = CheckIfVertexExistById(fromVertex);
            bool Check2 = CheckIfVertexExistById(toVertex);
            if(Check1 == true && Check2 == true)
            {
                bool Check3 = CheckIfEdgeExistById(fromVertex, toVertex);
                if(Check3==true)
                {
                    cout << "Edge between " << GetVertexById(fromVertex).GetName() << "(" << fromVertex << ") and " << GetVertexById(toVertex).GetName() << "(" << toVertex << ") Already Exist" << endl;
                }
                else
                {
                    for (int i = 0; i < v.size(); i++) 
                    {

                        if (v.at(i).GetId() == fromVertex) 
                        {
                            Edge e(toVertex, w);
                            v.at(i).e.push_back(e);
                        } 
                        else if (v.at(i).GetId() == toVertex) 
                        {
                            Edge e(toVertex, w);
                            v.at(i).e.push_back(e);
                        }
                    }
                    cout << "Edge between " << fromVertex << " and " << toVertex << " added Successfully" << endl;
                }
            }
        }

        void PrintGraph()
        {
            for(int i=0; i<v.size(); i++)
            {
                Vertex temp;
                temp = v.at(i);
                cout << temp.GetName() << " (" << temp.GetId() << ") -->";
                temp.GetEdgeList(); 
            }
        }
};

int main()
{
    Graph g;
    string name;
    int choice, id;
    Vertex v;
    do 
    {
        cout << "What operation do you want to perform? " <<
        " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Add Vertex" << endl;
        cout << "2. Update Vertex" << endl;
        cout << "3. Delete Vertex" << endl;
        cout << "4. Add Edge" << endl;
        cout << "5. Update Edge" << endl;
        cout << "6. Delete Edge" << endl;
        cout << "7. Check if 2 Vertices are Neigbors" << endl;
        cout << "8. Print All Neigbors of a Vertex" << endl;
        cout << "9. Print Graph" << endl;
        cout << "10. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;
        cin >> choice;
        switch(choice)
        {
            case 0:
            {
                break;
            }
            case 1:
            {
                cout << "Add Vertex Operation: " << endl;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                v.SetId(id);
                v.SetName(name);
                g.AddVertex(v);
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                break;
            }
            case 7:
            {
                break;
            }
            case 8:
            {
                break;
            }
            case 9:
            {
                cout << "Print Graph Operation: " << endl;
                g.PrintGraph();
                break;
            }
            default:
            {
                cout << "Enter Valid Choice." << endl;
                break;
            }
        }
    }
    while(choice!=0);
}