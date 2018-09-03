// This class models the Monte Carlo simulation for shortest paths in a graph

#ifndef GRAPH_SIM_H
#define GRAPH_SIM_H

#include "graph.h"

class graph_sim {
	private:
		int sim_iterations;
		int graph_vertices;
		double graph_weight_max;
		double graph_edge_density;

	public:
		graph_sim(const int sim_iterations, const int graph_vertices,
							const double graph_weight_max, const double graph_edge_density);
		int get_sim_iterations(void);
		int get_graph_vertices(void);
		double get_graph_weight_max(void);
		double get_graph_edge_density(void);
		void set_sim_iterations(const int sim_iterations);
		void set_graph_weight_max(const double graph_weight_max);
		void set_graph_edge_density(const double graph_edge_density);
		vector<double> sim_shortest_path(void);
};

// Constructor
graph_sim::graph_sim(const int sim_iterations, const int graph_vertices,
										 const double graph_weight_max,
										 const double graph_edge_density = 0.1) {
	assert(sim_iterations > 0);
	assert(graph_vertices > 0);
	assert(graph_weight_max > 0);
	assert(graph_edge_density >= 0 && graph_edge_density <= 1);

	this->sim_iterations = sim_iterations;
	this->graph_vertices = graph_vertices;
	this->graph_weight_max = graph_weight_max;
	this->graph_edge_density = graph_edge_density;
}

// Return the number of simulation iterations
int graph_sim::get_sim_iterations(void) {
	return(sim_iterations);
}

// Return the number of vertices in the graph
int graph_sim::get_graph_vertices(void) {
	return(graph_vertices);
}

// Return the graph_weight_max
double graph_sim::get_graph_weight_max(void) {
	return(graph_weight_max);
}

// Return the graph_edge_density
double graph_sim::get_graph_edge_density(void) {
	return(graph_edge_density);
}

// Set the sim_iterations
void graph_sim::set_sim_iterations(const int sim_iterations) {
	assert(sim_iterations > 0);
	this->sim_iterations = sim_iterations;
}

// Set the graph_weight_max
void graph_sim::set_graph_weight_max(const double graph_weight_max) {
	assert(graph_weight_max > 0);
	this->graph_weight_max = graph_weight_max;
}

// Set the graph_edge_density
void graph_sim::set_graph_edge_density(const double graph_edge_density) {
	assert(graph_edge_density >= 0 && graph_edge_density <= 1);
	this->graph_edge_density = graph_edge_density;
}

// Monte Carlo simulation for shortest paths in a graph
vector<double> graph_sim::sim_shortest_path(void) {
	double avg_spth = 0.0;
	vector<double> spth, sim_spth;
	graph g(false, graph_vertices);

	for (int i = 0; i < sim_iterations; i++) {
		g.random_graph(graph_edge_density, graph_weight_max);
		spth = g.shortest_path(0);
		avg_spth = accumulate(spth.begin(), spth.end(), 0.0) / spth.size();
		sim_spth.push_back(avg_spth);
	}

	return(sim_spth);
}

#endif //GRAPH_SIM_H
