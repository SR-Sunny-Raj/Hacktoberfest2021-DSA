class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
	string folderName;
	
	int i = 0;
	int n = path.length();

	while(i<n){
		// Extracting the folder name
		while(i<n && path[i] != '/'){
			folderName += path[i];
			i++;                
		}
		if(folderName.size() != 0){
			// For '.' do nothing
			if(folderName == "."){
				folderName.clear();
			}
			// For ".." go back one folder .i.e. remove '/' and 'previous folder'
			else if(folderName == ".."){
				// For removing folder name
				if(!st.empty()){
					st.pop();
				}
				// For removing /
				if(!st.empty()){
					st.pop();
				}
				folderName.clear();
			}
			else{
				st.push("/");
				reverse(folderName.begin(), folderName.end());
				st.push(folderName);
				folderName.clear();
			}
		}    
		i++;
	}
	string ans;
	while(!st.empty()){
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	
	return ans.empty() ? "/" : ans;
    }
};
