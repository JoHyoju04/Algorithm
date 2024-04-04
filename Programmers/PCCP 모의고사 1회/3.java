class Solution {
    public String[] solution(int[][] queries) {
        String[] result = new String[queries.length];
        for(int i = 0; i < queries.length; i++)
            result[i] = queries[i][0] == 1 ? "Rr" : bean(queries[i][0], queries[i][1]);
        return result;
    }
    private String bean(int n, int p) {
        if(n==1) return "Rr";

        String parent = bean(n-1,(p-1)/4+1);
        if(parent.equals("rr") || parent.equals("RR"))
            return parent;

        if(p % 4 == 0)
            return "rr";
        else if (p % 4 == 1)
            return "RR";
        else
            return "Rr";
    }
}