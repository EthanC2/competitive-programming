//Note: since 'isspace' is hella old, it can't be used as a unary predicate

string ltrim(string str)
{
    auto pos = find_if(str.cbegin(), str.cend(), [](char c){return isspace(c) == 0;});
    string::size_type idx = distance(str.cbegin(), pos);
    return str.substr(idx, string::npos);
}

string rtrim(string str)
{
    auto pos = find_if(str.rbegin(), str.rend(), [](char c){return isspace(c) == 0;}); 
    string::size_type idx = distance(str.begin(), pos.base());
    return str.substr(0, idx);
}

string trim(string str)
{
    return ltrim(move(rtrim(str)));
}
