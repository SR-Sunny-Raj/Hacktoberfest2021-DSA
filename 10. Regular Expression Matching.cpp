 bool isMatch(string s1, string s2) {
        if(s1 == s2) return true;
		 bool rr = false;
		if (s2.size() > 1 && s2[1] == '*') {
            int i =0;
			while (i < s1.size() && ((s1[i] == s2[0]) || (s2[0] == '.') ))
			{
				rr = rr | isMatch(s1.substr(i), (s2.size() > 2 ?s2.substr(2):""));
				i++;
			}
            
            rr = rr | isMatch(i < s1.size() ? s1.substr(i) : "", (s2.size() > 2 ?s2.substr(2):""));
		}
		else if (s2.size()>0 && s1.size() > 0 && ((s2[0] == '.') || (s2[0] == s1[0])))
			rr = rr | isMatch((s1.size() > 1 ?s1.substr(1):""), (s2.size() > 1 ?s2.substr(1):""));

		return rr;
    }
};
