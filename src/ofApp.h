#pragma once

#include "ofMain.h"
#include "ofxMtlMapping2D.h"
#include "ofxMovieExporter.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    //DHRAMA MASK
    ofImage mask;
    ofVideoPlayer mov1;
    ofVideoPlayer mov2;
    
    int x_pos;
    int y_pos;
    int x_size;
    int y_size;
    
    
    float movSpeed = 1;
    
    float mult = 1;
    
    
    void setupDhrama(){
        
        ofBackground(0, 0, 0,255);
        
        //init video
        ofSetVerticalSync(true);
        mov1.loadMovie("mov2_1024.mp4");
        mov1.setLoopState(OF_LOOP_NORMAL);
        mov1.setVolume(0);
        mov1.play();
        
        //init mask
        
        mask.loadImage("mask_5k.png");
        
        
        x_pos = (ofGetWidth() - mask.getWidth())/2.0;
        y_pos = (ofGetHeight() - mask.getHeight())/2.0;
        
        x_size = mask.getWidth();
        y_size = mask.getHeight();

        
    }
    
    void updateDhrama(){
        mov1.update();
    }
    
    
    void drawDhrama(){
        
        
        mov1.draw(0,0);
        mask.draw(x_pos, y_pos, x_size * mult, y_size * mult);
        
    }
    
    void mouseMovedDhrama(int x, int y){
        mult = ofMap(mouseX, 0, 1024, 0.2, 6);
        
        x_pos = (ofGetWidth() - mask.getWidth() *mult)/2.0;
        y_pos = (ofGetHeight() - mask.getHeight()*mult)/2.0;
        
    }

    
    //MOVIE EXPORTER
    
    void setupExporter(){
        
        ofSetFrameRate(60);
        testImage.loadImage("kate-1024-768.jpg");
        movieExporter.setup();
        
    }
    
    void drawExporter(){
        if (movieExporter.isRecording())
        {
//            ofSetColor(255, 0, 0);
//            ofDrawBitmapString("Press space to stop recording", 10, 15);
        }
//        else ofDrawBitmapString("Press space to start recording", 10, 15);

    }
    
    void keyPressedExporter(int key){
        
        switch (key)
        {
            case ' ':
                if (movieExporter.isRecording()) movieExporter.stop();
                else movieExporter.record();
                break;
                
            case '1':
                movSpeed -= 0.1;
                break;
            case '2':
                movSpeed += 0.1;
                break;
        }
        mov1.setSpeed(movSpeed);
        ofLog() << "video speed: " << movSpeed;
    }
    
    
    //MAPPING
    
    void setupMapping(){
        ofSetFrameRate(30);
//        ofBackground(50);
        
        // ----
        _mapping = new ofxMtlMapping2D();
        _mapping->init(ofGetWidth(), ofGetHeight(), "mapping/xml/shapes.xml", "mapping/controls/mapping.xml");

    }
    
    void updateMapping(){
            _mapping->update();
    }
    
    void drawMapping(){
        // ----
        _mapping->bind();
        
        _mapping->chessBoard();
        
        drawDhrama();
        
        
        
        _mapping->unbind();

        _mapping->draw();

    }
    private:
    //MAPPING
        ofxMtlMapping2D* _mapping;
    //MOVIE EXPORTER
        Apex::ofxMovieExporter movieExporter;
        ofImage testImage;
		
};
