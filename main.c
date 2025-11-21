#include <stdio.h>
#include <gtk/gtk.h>

void screenAddWidget();





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
    GtkWidget *entryWidgetName = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParentWidgets),entryWidgetName,0,0,8,1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entryWidgetName),"Enter Widget Name");
    //Margins & Paddings
    gtk_widget_set_size_request(entryWidgetName,210,-1);

    //Init of dropdownWidgets
    const char *widgetList[]={"Button","Entry",NULL};
    GtkStringList *listWidgets = gtk_string_list_new(widgetList);
    GtkWidget *dropdownWidgets = gtk_drop_down_new(G_LIST_MODEL (listWidgets), NULL);
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


    //Init of entryGridPlacementRow
    GtkWidget *entryGridPlacementRow = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParentWidgets),entryGridPlacementRow,1,3,5,1);

    //Init of labelGridPlacementColumn
    GtkWidget *labelGridPlacementColumn = gtk_label_new("Col:");
    gtk_grid_attach(GTK_GRID(gridParentWidgets),labelGridPlacementColumn,6,3,1,1);
    gtk_widget_set_margin_top(labelGridPlacementColumn,4);

    //Init of entryGridPlacementColumn
    GtkWidget *entryGridPlacementColumn = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParentWidgets),entryGridPlacementColumn,7,3,3,1);




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

