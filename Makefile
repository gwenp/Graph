all: oriented-graph

oriented-graph: oriented-graph.cc ListGraph/ListGraph.cc
	g++ -I. -I.. $^ -o $@

clean:
	rm -f oriented-graph

.PHONY: all clean
