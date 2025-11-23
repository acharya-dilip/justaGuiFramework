#include <stdio.h>
#include <gtk/gtk.h>

struct widgets{
    int isOccupied;
    char widgetName[100];
    GtkWidget *widget;
    struct label{
        char label[100];
    }label;
    struct grid {
        int row;
        int col;
    }grid;
    struct widgetType {
        int isButton;
        int isEntry;
    }type;
    struct button {
        char label[100];
    }button;
    struct entry {
        int hasPlaceholderText;
        char placeholderText[100];
        int hasPreText;
        char preText[100];
        int isEditable;
    }entry;
}widget[100];

void screenAddWidget();
void registerWidget();

//Glovbized Varuables
GtkWidget *entryWidgetName;
GtkWidget *dropdownWidgets;
GtkWidget *spinbuttonGridPlacementRow;
GtkWidget *spinbuttonGridPlacementColumn;
GtkWidget *entryLabel;
const char *widgetList[]={"Button","Entry",NULL};
GtkStringList *listWidgets;
//Init of defaultAdjustment
GtkAdjustment *defaultAdjustment = gtk_adjustment_new(0.0, 0.0, 100.0, 1.0, 10.0, 0.0);


void screenAddWidget() {

    //Init of windowAddWidget
    GtkWidget *windowAddWidget = gtk_window_new();
    gtk_window_set_default_size(GTK_WINDOW(windowAddWidget),300,300);
    gtk_window_set_title(GTK_WINDOW(windowAddWidget),"Add Widget");
    gtk_window_present(GTK_WINDOW(windowAddWidget));

    //Init of gridParentWidgets
    GtkWidget *gridParentWidgets = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(windowAddWidget),gridParentWidgets);
    //Margins & Paddings
    gtk_widget_set_margin_top(gridParentWidgets,10);
    gtk_widget_set_margin_bottom(gridParentWidgets,10);
    gtk_widget_set_margin_end(gridParentWidgets,10);
    gtk_widget_set_margin_start(gridParentWidgets,10);

    //Init of entryWidgetName
    entryWidgetName = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParentWidgets),entryWidgetName,0,0,8,1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entryWidgetName),"Enter Widget Name");
    //Margins & Paddings
    gtk_widget_set_size_request(entryWidgetName,210,-1);

    //Init of dropdownWidgets
    listWidgets = gtk_string_list_new(widgetList);
    dropdownWidgets = gtk_drop_down_new(G_LIST_MODEL (listWidgets), NULL);
    gtk_grid_attach(GTK_GRID(gridParentWidgets),dropdownWidgets,8,0,2,1);

    //Init of labelPlacement
    GtkWidget *labelPlacement = gtk_label_new("Grid Placement:");
    gtk_grid_attach(GTK_GRID(gridParentWidgets),labelPlacement,0,2,6,1);
    gtk_widget_set_halign(labelPlacement,GTK_ALIGN_START);
    gtk_widget_set_margin_start(labelPlacement,6);
    gtk_widget_set_margin_top(labelPlacement,6);
    gtk_widget_set_margin_bottom(labelPlacement,10);

    //Init of labelGridPlacementRow
    GtkWidget *labelGridPlacementRow = gtk_label_new("Row:");
    gtk_grid_attach(GTK_GRID(gridParentWidgets),labelGridPlacementRow,0,3,1,1);
    gtk_widget_set_margin_top(labelGridPlacementRow,4);


    //Init of spinbuttonGridPlacementRow
    spinbuttonGridPlacementRow = gtk_spin_button_new(defaultAdjustment,1,0);
    gtk_grid_attach(GTK_GRID(gridParentWidgets),entryGridPlacementRow,1,3,5,1);

    //Init of labelGridPlacementColumn
    GtkWidget *labelGridPlacementColumn = gtk_label_new("Col:");
    gtk_grid_attach(GTK_GRID(gridParentWidgets),labelGridPlacementColumn,6,3,1,1);
    gtk_widget_set_margin_top(labelGridPlacementColumn,4);

    //Init of entryGridPlacementColumn
    entryGridPlacementColumn = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParentWidgets),entryGridPlacementColumn,7,3,3,1);

    //Init of entrylabel
    entryLabel = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParentWidgets),entryLabel,0,4,10,1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entryLabel),"Enter Widget Label");


    //Init of buttonAddWidget
    GtkWidget *buttonRegisterWidget = gtk_button_new_with_label("Add Widget");
    gtk_grid_attach(GTK_GRID(gridParentWidgets),buttonRegisterWidget,0,20,10,1);
    g_signal_connect(buttonRegisterWidget,"clicked",G_CALLBACK(registerWidget),NULL);


}
int widgetCount;
void  registerWidget(){
    //Function to hold all the logic for when the buttonRegister
    widget[widgetCount].isOccupied = 1;
    strcpy(widget[widgetCount].widgetName,gtk_editable_get_text(GTK_EDITABLE(entryWidgetName)));
    const char *widgetType = gtk_string_list_get_string(GTK_STRING_LIST(listWidgets), gtk_drop_down_get_selected(GTK_DROP_DOWN(dropdownWidgets)));
    if(strcmp(widgetType,"Button")==0){
    widget[widgetCount].widget = gtk_button_new_with_label(gtk_editable_get_text(GTK_EDITABLE(entryLabel)));

}
    else if(strcmp(widgetType,"Label")==0){}
    else if(strcmp(widgetType,"Entry")==0){}

}
static void activate(GtkApplication *app,gpointer user_data) {

    //init of windowMain
    GtkWidget *windowMain = gtk_application_window_new(app);
    gtk_window_set_default_size(GTK_WINDOW(windowMain),400,500);
    gtk_window_set_title(GTK_WINDOW(windowMain),"JustaGuiFramework");
    gtk_window_present(GTK_WINDOW(windowMain));

    //init of headerMain
    GtkWidget *headerMain = gtk_header_bar_new();
    gtk_window_set_titlebar(GTK_WINDOW(windowMain),headerMain);

    //init of button add widget
    GtkWidget *buttonAddWidget = gtk_button_new_with_label("➕");
    gtk_header_bar_pack_start(GTK_HEADER_BAR(headerMain),buttonAddWidget);
    g_signal_connect(buttonAddWidget,"clicked",G_CALLBACK(screenAddWidget),NULL);

    //init buttonChildWindow
    GtkWidget *buttonChildWindow = gtk_button_new_with_label("🧭");
    gtk_header_bar_pack_start(GTK_HEADER_BAR(headerMain),buttonChildWindow);

}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;
    app= gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}

