#include <iostream>
#include <string>
using namespace std;

class MediaFile{
	protected:
		int fileSize;
		string filePath;

	public:
		MediaFile(int fS, string fP): fileSize(fS), filePath(fP){}

		virtual void play(){
			cout << "The file is now playing!" << endl;
		}

		virtual void stop(){
			cout << "The file has now stopped playing!" << endl;
		}

		virtual ~MediaFile() {}
};

class VisualMedia: virtual public MediaFile{

	public:
		VisualMedia(int fS, string fP): MediaFile(fS, fP){}

		void playVisuals(){
			cout << "The visuals are now playing!" << endl;
		}
};

class AudioMedia: virtual public MediaFile{

	public:
		AudioMedia(int fS, string fP): MediaFile(fS, fP){}

		void playAudio(){
			cout << "The audio is now playing!" << endl;
		}
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(int fS, string fP) 
        : MediaFile(fS, fP), VisualMedia(fS, fP), AudioMedia(fS, fP) {}


    void play() override {
        cout << "Playing video file: " << filePath << endl;
        playVisuals();
        playAudio();
    }

    void stop() override {
        cout << "Stopping video file: " << filePath << endl;
    }
};

class ImageFile : public VisualMedia {
public:
    ImageFile(int fS, string fP) : MediaFile(fS, fP), VisualMedia(fS, fP) {}

    void play() override {
        cout << "Displaying image file: " << filePath << endl;
        playVisuals();
    }
};


class AudioFile : public AudioMedia {
public:
    AudioFile(int fS, string fP) : MediaFile(fS, fP), AudioMedia(fS, fP) {}

    void play() override {
        cout << "Playing audio file: " << filePath << endl;
        playAudio();
    }
};



int main(){

	MediaFile* mediaLibrary[] = {
		new VideoFile(500, "video.mp4"),
        new ImageFile(200, "image.jpg"),
        new AudioFile(300, "audio.mp3")
	};

	for(MediaFile* file : mediaLibrary){
		file->play();
		file->stop();
		cout << "-------------------\n";
	}

	for(MediaFile* file : mediaLibrary){
		delete file;
	}

	return 0;
}