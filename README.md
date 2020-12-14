# Intro2robo_final_project : Waster segregation by OWI robot arm 

## Motivaton for the project

Disposal of waste is one of the biggest issues the world is facing today. Increasing incenerators ad lanfills not only cause pollution but are also extremely expensive methods of waste disposal. Segregation of waste is important for properly disposing of the vast amount of garbage modern society produces in an environmentally conscious manner. Different components of waste have very different properties, and grouping them by type allows for proper processing or storage. In this project we have divided the houshold wastes into four categories : Paper, Metal, Plastic and Glass.

## Voice controlled waste segregation

We used the OWI arm setup. The arduino was interfaced to a bluetooth module. Voice commands for segregating waste is 
given on an Anroid app which are transmitted to the bluetooth module. Based on these commands of the type of waste, 
the robot arm sorts the objects.

The code for this project is in **'Voice_recognition.io'**.

## Waste segregation using object detection in computer vision

1. Clone the Tensorflow models repository using $ git clone https://github.com/tensorflow/models.git.

2. Collect data : We prepared a dataset of 200 images of plastic, paper, metal and glass. 
You can find the images in **Dataset**.

3. Split into Train and Test data ; Our ratio was 80:20 for train:test.

4. Labeling the Dataset : We labeled the images using LabelImg. You can find the xmls in **labels**.

5. Create LabelMap (.pbtxt) : Classes need to be listed in the label map. 

6. Convert XML to CSV file(.csv) : In this code we are creating a CSV file which contains all the XML files and their bounding box co-ordinates to single CSV file which is input for creating TFrecords.

7. Create TFRecord (.record) : TFRecord is an important data format designed for Tensorflow. We used generate_tf_record.py to convert our data set into train.record and test.record.

8. Download pre-trained model :There are many pre-trained object detection models available in the model zoo. In order to train  our custom data set, the models need to be restored in Tensorflow using their checkpoints (.ckpt files), which are records of previous model states. We used ssd_mobilenet_v2_coco.

9. Modify Config (.config) File : Each of the pretrained models has a config file that contains details about the model. To detect our custom class, the config file needs to be modified accordingly.
 
10. Training the models : 
#Change into the models directory
$ cd tensorflow/models
#Make directory for storing training progress
$ mkdir train
#Make directory for storing validation results
$ mkdir eval
#Begin training
$ python research/object_detection/train.py \
    --logtostderr \
    --train_dir=train \
    --pipeline_config_path=ssd_mobilenet_v2_coco.config
    
11. Model export :Once you finish training your model, you can export your model to be used for inference.

12. 




