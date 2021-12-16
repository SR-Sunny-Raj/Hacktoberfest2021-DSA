import moviepy.editor
x = input("Enter The Path Of The Video : ")
video = moviepy.editor.VideoFileClip(x)
audio = video.audio
lctnaudio = input("\nEnter The Location where the file to be stored : ")
audio.write_audiofile(lctnaudio)
