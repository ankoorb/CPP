#ifndef ROUTE_MODEL_H
#define ROUTE_MODEL_H

#include <limits>
#include <cmath>
#include <unordered_map>
#include "model.h"
#include <iostream>

class RouteModel : public Model {

  public:
    class Node : public Model::Node {
      public:
        Node* parent = nullptr;
        float h_value = std::numeric_limits<float>::max();
        float g_value = 0.0;
        bool visited = false;
        std::vector<Node*> neighbors;

        void FindNeighbors();
        float distance(Node other) const {
            return std::sqrt(std::pow((x - other.x), 2) + std::pow((y - other.y), 2));
        }

        Node(){}
        Node(int idx, RouteModel * search_model, Model::Node node) : Model::Node(node), parent_model(search_model), index(idx) {}

      private:
        int index;
        Node* FindNeighbor(std::vector<int> node_indices);
        RouteModel * parent_model = nullptr;
    };

    RouteModel(const std::vector<std::byte> &xml);
    Node& FindClosestNode(float x, float y);
    auto& SNodes() { return m_Nodes; } // Return a reference to the vector of Nodes stored as m_Nodes
    std::vector<Node> path;
    auto& GetNodeToRoadMap(){ return node_to_road; } // Return a reference to the node_to_road variable
    
  private:
    void CreateNodeToRoadHashmap();
    std::unordered_map<int, std::vector<const Model::Road *>> node_to_road; // Hash table of Node index values to a vector of Road pointers that those nodes belong to.
    std::vector<Node> m_Nodes;  // Store all of the nodes from the Open Street Map data

};

#endif
