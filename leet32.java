class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);
        
        List<String> ans = new ArrayList<>();
        ans.add(folder[0]);
        for (int i = 1; i < folder.length; i++) {
            // Get the last added folder path and add a trailing slash
            String lastFolder = ans.get(ans.size() - 1) + "/";
            
            if (!folder[i].startsWith(lastFolder)) {
                ans.add(folder[i]);
            }
        }
        
        return ans;
    }
}
