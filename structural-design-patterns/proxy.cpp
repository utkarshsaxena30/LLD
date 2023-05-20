/* 
Imagine you are developing a multimedia streaming application that allows users to watch videos. The application relies on 
a remote video server that provides access to a large collection of videos. However, retrieving and playing videos directly 
from the server can be slow and resource-intensive, especially for high-resolution videos.

Your task is to implement the Proxy pattern to optimize the video streaming process. Create an interface called Video that 
defines the common methods for retrieving and playing videos. Then, create a RealVideo class that implements the Video 
interface and represents the actual video objects stored on the remote server.

Next, create a ProxyVideo class that also implements the Video interface. The ProxyVideo class should act as a proxy for the 
RealVideo objects and provide additional functionalities such as caching, lazy loading, or access control.

The ProxyVideo should handle the retrieval and caching of video data from the remote server. If a video is requested for the 
first time, the ProxyVideo should load it from the server and cache it for future use. Subsequent requests for the same 
video should be served from the cache, avoiding the need for repeated network requests.

Demonstrate the usage of the Proxy pattern by creating instances of ProxyVideo and accessing videos through the proxy. Verify
that the proxy effectively manages the retrieval and caching of video data, providing a seamless video streaming experience 
for users.
*/

#include<iostream>
#include<string>
#include<unordered_map>

class Video {
    public: 
        virtual std::string getVideo(std::string title) = 0;
};

class RealVideo: public Video {
    public: 
        std::string getVideo(std::string title) override {
            return "Video: " + title;
        }
};

class ProxyVideo: public Video {
    private:
        RealVideo *realVideo_; 
        std::unordered_map<std::string, std::string> cache_;
    public: 
        ProxyVideo(): realVideo_(new RealVideo()) {}
        std::string getVideo(std::string title) override {
            if(cache_.find(title) == cache_.end()) {
                cache_[title] = realVideo_->getVideo(title);
                return cache_[title];
            }
            return "Cached entry: " + cache_[title];
        }
};

int main() {
    Video *video = new ProxyVideo();
    std::cout << video->getVideo("title A") << std::endl;
    std::cout << video->getVideo("title B") << std::endl;
    std::cout << video->getVideo("title A") << std::endl;
}