#include <stdio.h>
#include <gtk/gtk.h>
struct widgets{
    int isOccupied;
    char widgetName[100];
    GtkWidget *widget;

    //For the display thing
    GtkWidget *boxWidgetInfo;
    GtkWidget *gridChildBox;
    GtkWidget *labelWidgetInfo;
    GtkWidget *buttonDeleteWidget;

    struct label{
        char label[100];
    }label;
    struct grid {
        int row;
        int col;
        int rowSpan;
        int colSpan;
    }grid;
    struct minSize{
        int height;
        int width;
    }minSize;
    struct widgetType {
        char widgetTypeName[100];
        int isButton;
        int isEntry;
        int isLabel;
        int isTextView;
    }type;
    struct button {
        char label[100];
    }button;
    struct entry {
        int hasPlaceHolderText;
        char placeholderText[100];
    }entry;
    struct margins {
        int top;
        int bottom;
        int start;
        int end;
    }margin;
}widget[100];
int widgetCount;
void declareWidgets() {
    //Sets the widgets as null
    int i=0;
    while (widget[i].widget!=NULL) {
        widget[i].widget=NULL;
        i++;
    }
    for (int j = 0; j<widgetCount;j++) {
        if (widget[j].type.isButton==1) {
            widget[j].widget = gtk_button_new_with_label(widget[j].button.label);
        }else if (widget[j].type.isLabel==1){
            widget[j].widget = gtk_label_new(widget[j].label.label);
        }else if (widget[j].type.isTextView==1){
            widget[j].widget = gtk_text_view_new();
        }else if (widget[j].type.isEntry==1) {
            widget[j].widget = gtk_entry_new();
            if (widget[j].entry.hasPlaceHolderText==1) {
                gtk_entry_set_placeholder_text(GTK_ENTRY(widget[j].widget),widget[j].entry.placeholderText);
            }
        }
        gtk_widget_set_margin_top(widget[j].widget,widget[j].margin.top);
        gtk_widget_set_margin_bottom(widget[j].widget,widget[j].margin.bottom);
        gtk_widget_set_margin_start(widget[j].widget,widget[j].margin.start);
        gtk_widget_set_margin_end(widget[j].widget,widget[j].margin.end);

    }
}

void readWidgetData() {
    FILE *file = fopen("widget.data","r");
    fread(&widgetCount, sizeof(widgetCount), 1, file);
    fread(&widget,sizeof(widget),widgetCount,file);
    fclose(file);
}

void yourCode();

static void activate(GtkApplication *app,gpointer user_data) {
    //Init of windowChild
    GtkWidget *windowChild = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(windowChild),"JustaGuiFramework");
    gtk_window_set_default_size(GTK_WINDOW(windowChild),200,200);
    gtk_window_present(GTK_WINDOW(windowChild));

    //Init of gridParent
    GtkWidget *gridParent = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(windowChild),gridParent);
    //MArgins & Paddings
    gtk_widget_set_margin_start(gridParent,10);
    gtk_widget_set_margin_end(gridParent,10);
    gtk_widget_set_margin_top(gridParent,10);
    gtk_widget_set_margin_bottom(gridParent,10);
    gtk_widget_set_halign(gridParent,GTK_ALIGN_CENTER);
    gtk_widget_set_valign(gridParent,GTK_ALIGN_CENTER);


    //Declares the widgets with their appropiriate widgetType
    readWidgetData();
    declareWidgets();
    for (int i=0;i<widgetCount;i++) {
        if (widget[i].isOccupied==1) {
            gtk_grid_attach(GTK_GRID(gridParent),widget[i].widget,
            widget[i].grid.col,
            widget[i].grid.row,
            widget[i].grid.colSpan,
            widget[i].grid.rowSpan);
            gtk_widget_set_size_request(widget[i].widget,
                widget[i].minSize.width,
                widget[i].minSize.height);
        }
    }
    //You can put your code here do not touch the other stuff you didn't create
    yourCode();

}

void yourCode() {
    //Put yo code here read the documentation of the widgets


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