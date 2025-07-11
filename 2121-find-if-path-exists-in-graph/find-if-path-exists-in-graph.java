class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        
        List<List<Integer>> graph = new ArrayList<>();
        boolean[] vis = new boolean[n];

        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }

    return hasPath(graph, source, destination, vis);
    }

    private boolean hasPath(List<List<Integer>> graph, int source, int destination, boolean[] vis) {
        if (source == destination) {
            return true;
        }

        vis[source] = true;

        for (int neighbor : graph.get(source)) {
            if (!vis[neighbor]) {
                if (hasPath(graph, neighbor, destination, vis)) {
                    return true;
                }
            }
        }

        return false;
    }
}