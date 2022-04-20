vector<string> split_ws(string str)
{
    vector<string> words;
    string buffer;

    for(char c : str)
    {
        if (isspace(c))
        {
            words.push_back(buffer);
            buffer.clear();
        }
        else
        {
            buffer += c;
        }
    }
    
    //Push remaining buffer
    words.push_back(buffer);

    return words;
}
