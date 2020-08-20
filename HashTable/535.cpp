// TinyURL是一种URL简化服务， 比如：当你输入一个URL https://leetcode.com/problems/design-tinyurl 时，它将返回一个简化的URL http://tinyurl.com/4e9iAk.

// 要求：设计一个 TinyURL 的加密 encode 和解密 decode 的方法。你的加密和解密算法如何设计和运作是没有限制的，你只需要保证一个URL可以被加密成一个TinyURL，并且这个TinyURL可以用解密方法恢复成原本的URL。


class Solution {
    
private:
    
    map<string, string> pair;//哈希表 用来映射长短网址的对应关系
    
    char chr[62] = {'0','1','2','3','4','5','6','7','8','9',
                  'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                  'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};//生成短码用的字符合集(可以交叉排布以使生成的短码看起来更“均匀”～)
    
    int size = 6;//定义生成的短码长度
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        string shortUrl;
        
        while(true){//避免生成的短码重复（虽然可能性很小）
            
            string short_code = "";
            
            srand(int(time(0)));//重置乱数
            for(int i=0; i<size; i++){//随机生成6位短码
                
                int index = rand()%61;
                short_code += chr[index];
            }
            
            shortUrl = "http://tinyurl.com/" + short_code;
            
            auto it = pair.find(shortUrl);//定义迭代器
            if(it==pair.end())
                break;
            
        }

        pair[shortUrl] = longUrl;//将生成的短网址和其对应的长网址成对插入到哈希表中
        
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        auto it = pair.find(shortUrl);//定义迭代器
        
        string long_code;
        
        if(it!=pair.end()){//在哈希表中查找短网址 找到后删除（这里的设计使得每个短码是一次性的，用过即作废）
            
            long_code = it->second;
            pair.erase(it);
        }
            

        return long_code;
    }
};
