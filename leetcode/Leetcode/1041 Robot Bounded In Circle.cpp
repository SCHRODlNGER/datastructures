
pair<int, int> turn_left(pair<int, int> a){
    if(a == make_pair(1, 0))
        return {0, 1};
    if( a == make_pair(0, 1))
        return {-1, 0};
    if( a == make_pair(-1, 0))
        return {0, -1};
    return {1, 0};
}

pair<int, int> turn_right(pair<int, int> a){
    if(a == make_pair(1, 0))
        return {0, -1};
    if( a == make_pair(0, 1))
        return {1, 0};
    if( a == make_pair(-1, 0))
        return {0, 1};
    return {-1, 0};
}

bool isRobotBounded(string s) {
    
    pair<int, int> a = {0, 0};
    pair<int, int> cur = {1, 0};
    
    for(int i=0;i<s.length();i++){
        if(s[i] == 'G')
            a = {a.first + cur.first, a.second + cur.second};
        else if(s[i] == 'L')D
            cur = turn_left(cur);
        else
            cur = turn_right(cur);
    }
    if( cur != make_pair(1, 0) || (a.first == 0 && a.second == 0))
        return true;
    return false;
    
}