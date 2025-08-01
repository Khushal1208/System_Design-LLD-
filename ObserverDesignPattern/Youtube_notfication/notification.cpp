#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class ISubscriber {
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {} // Virtual destructor for interface
};

class IChannel {
public:
    virtual void subscribe(ISubscriber* s) = 0;
    virtual void unsubscribe(ISubscriber* s) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~IChannel() {}
};

class Channel : public IChannel {
private:
    vector<ISubscriber*> subscribers;
    string name, latestVideo;

public:
    Channel(const string& name) {
        this->name = name;
    }

    void subscribe(ISubscriber* subscriber) override {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it == subscribers.end()) {
            subscribers.push_back(subscriber);
        }
    }

    void unsubscribe(ISubscriber* subscriber) override {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    void notifySubscribers() override {
        for (ISubscriber* sub : subscribers) {
            sub->update();
        }
    }

    void uploadVideo(const string& title) {
        latestVideo = title;
        cout << "\n[" << name << " uploaded \"" << title << "\"]\n";
        notifySubscribers();
    }

    string getVideoData() {
        return "\nCheckout our new Video: " + latestVideo + "\n";
    }
};

class Subscriber : public ISubscriber {
private:
    string name;
    Channel* channel;

public:
    Subscriber(const string& name, Channel* channel) {
        this->name = name;
        this->channel = channel;
    }

    void update() override {
        cout << "Hey " << name << "," << this->channel->getVideoData();
    }
};

int main() {
    Channel* channel = new Channel("CoderArmy");

    Subscriber* subs1 = new Subscriber("Varun", channel);
    Subscriber* subs2 = new Subscriber("Tarun", channel);

    channel->subscribe(subs1);
    channel->subscribe(subs2);

    channel->unsubscribe(subs1);
    channel->uploadVideo("Decorator Pattern Tutorial");

    // Clean up memory
    delete subs1;
    delete subs2;
    delete channel;

    return 0;
}
