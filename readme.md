# JustaGUIFrameWork
A GUI framework for a GUI Framework.<br>
Made completely using C and GTK4 JustaGUIFrameWork is a GUI framework that lets you create
GUI using a GUI which is based on GTK4. Sounds Confusing? Worry Not Just clone right in.
Start navigating and adding your widgets and export the GUI where a template file will be waiting for you
and your widget data you can start adding your code to that template file while also using the generated
documentation of your given widgets in order to provide you with a flawless experience.

# How to Use?
- Click the ➕ to start adding widgets to your GUI
- Configure the different settings for the widget from it's type to it's size and margins
- Once you're done register the widget and you can see it pop up in the main screen.
- If you're dissatisfied or a widget was configured wrong you can simply click the ❌ button besides the widget info label to delete it
- Once you're done adding all your widgets press the 🧭 for a preview
- When you're satisfied with your GUI click the Export button to export the widget data and documentation
- Check the Exported GUI directory for your widget data and documentation.
- Start writing your code in the provided template main.c inside the Exported GUI to add your own functionality to the GUI that you created"

## GEEEEE TEEEEEE YAYYYYY!!!

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
