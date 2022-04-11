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




//Templated versions
template <typename StrT = string, typename CharT = char, typename enable = typename enable_if<is_base_of<basic_string<CharT>,StrT>::value>::type>
StrT ltrim(StrT str)
{
    auto pos = find_if(str.cbegin(), str.cend(), [](char c){return isspace(c) == 0;});
    typename StrT::size_type idx = distance(str.cbegin(), pos);
    return str.substr(idx, string::npos);
}

template <typename StrT = string, typename CharT = char, typename enable = typename enable_if<is_base_of<basic_string<CharT>,StrT>::value>::type>
StrT rtrim(StrT str)
{
    auto pos = find_if(str.rbegin(), str.rend(), [](char c){return isspace(c) == 0;});
    typename StrT::size_type idx = distance(str.begin(), pos.base());
    return str.substr(0, idx);
}

template <typename StrT = string, typename CharT = char, typename enable = typename enable_if<is_base_of<basic_string<CharT>,StrT>::value>::type>
StrT trim(StrT str)
{
    return ltrim(move(rtrim(str)));
}
