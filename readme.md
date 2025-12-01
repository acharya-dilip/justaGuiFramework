# JustaGUIFrameWork
A GUI framework for a GUI Framework.<br>
Made completely using C and GTK4 JustaGUIFrameWork is a GUI framework that lets you create
GUI using a GUI which is based on GTK4. Sounds Confusing? Worry Not Just clone right in.
Start navigating and adding your widgets and export the GUI where a template file will be waiting for you
and your widget data you can start adding your code to that template file while also using the generated
documentation of your given widgets in order to provide you with a flawless experience.
Also You can now import previously exported widgets and edit them now in your own comfort of JustaGuiFramework and
reexport it to your chosen directory

# How to Use?
- Click the ➕ to start adding widgets to your GUI
- Or Click the import button to import widget.data file of a previously exported GUI
- Configure the different settings for the widget from it's type to it's size and margins
- Once you're done register the widget and you can see it pop up in the main screen.
- If you're dissatisfied or a widget was configured wrong you can simply click the ❌ button besides the widget info label to delete it
- Or you can click the 📝 button to edit the widgets properties till you're satisfied
- Once you're done adding all your widgets press the 🧭 for a preview
- When you're satisfied with your GUI click the Export button 
- Choose the directory you want the file to export to else it will export the the default path
- Check the Exported GUI directory for your widget data and documentation.
- Start writing your code in the provided template main.c inside the Exported GUI to add your own functionality to the GUI that you created"

## GEEEEE TEEEEEE YAYYYYY!!!

# What's New in the second itiration?
- Firstly added a screen and option to edit the properties of already exsisting widgets
- Made some changes to how the UI looked and changed the widget info labels with frames instead of boxes
- Added a button for importing previously exported GUI's and added support for the editing of previous GUI's and stuff
- Made some functions recursive and reusable for code efficiency and my sanity
- Reduced the number of globally declared widgets and made as many I could to local 
- Added a export file screen that pops up when you press the export button which lets you choose a path for you to export your widget.data file.

# Demo Video
-

# Arch Linux Build Instructions
| Commands                                            | What They Do?                     |
|-----------------------------------------------------|-----------------------------------|
| git clone https://github.com/acharya/justaGuiFramework.git | Clones into the gh repo           |
| cd justaGuiFramework                                | Navigates into the justaGuiFramework dir |
| chmod +x install.sh                                 | Makes the install.sh be runnable  |
| ./install.sh                                        | Runs the install Script           |
| cd build                                            | Navigates into the build dir      |
| ./justaGuiFramework                                       | Runs the application              |

# What's inside the install.sh?
| Commands                  | What They Do?                |
|---------------------------|------------------------------|
| sudo pacman -S base-devel | Installs Base devel          |
| sudo pacman -S cmake      | Installs Cmake               |
| sudo pacman -S gtk        | Installs GTK                 |
| cd build                  | Navigates into the build dir |
| cmake ..                  | Checks for the Cmake file    |
| cmake --build .           | Executes the build           |

# Credit Goes To
- @HolyBasil => This Guy Spent like 7 and a half hours on a single day cuz
  he spent the rest of the week procasitnating and now he's doomed
  cause he hasn't gotten enough sleep and his schools starts in 2 hours again!
- contactme: acharyamission6@gmail.com
- I had fun building this and am partly proud that I built smth liek this cause if I can refine this enough it might actually be a good framework
- Btw this project is a framework for a framework that fits the theme framework which in turn gets me closer to a framework
- Confusing Right? Worry Not This is justaGuiFramework hehehehehe