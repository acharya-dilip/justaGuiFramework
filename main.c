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

