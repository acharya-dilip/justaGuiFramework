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
void screenAddWidget();
void registerWidget();
void declareWidgetLabels();
void deleteWidget(GtkButton *button, gpointer user_data);
void screenWindowChild();
void exportGui();
void declareWidgets();
void updateAddWidgets();
//Glovbized Varuables
GtkWidget *windowAddWidget;
GtkWidget *entryWidgetName;
GtkWidget *dropdownWidgets;
GtkWidget *spinbuttonGridPlacementRow;
GtkWidget *spinbuttonGridPlacementColumn;
GtkWidget *spinbuttonGridPlacementRowSpan;
GtkWidget *spinbuttonGridPlacementColumnSpan;
GtkWidget *spinbuttonMinHeight;
GtkWidget *spinbuttonMinWidth;
GtkWidget *spinbuttonMarginStart;
GtkWidget *spinbuttonMarginEnd;
GtkWidget *spinbuttonMarginTop;
GtkWidget *spinbuttonMarginBottom;
GtkWidget *entryLabel;
const char *widgetList[]={"Button","Label","Entry","T.View",NULL};
GtkStringList *listWidgets;
//Init of defaultAdjustment
GtkAdjustment *defaultAdjustmentRow;
GtkAdjustment *defaultAdjustmentColumn;
GtkAdjustment *defaultAdjustmentRowSpan;
GtkAdjustment *defaultAdjustmentColumnSpan;
GtkAdjustment *defaultAdjustmentMinHeight;
GtkAdjustment *defaultAdjustmentMinWidth;
GtkAdjustment *defaultAdjustmentMarginStart;
GtkAdjustment *defaultAdjustmentMarginEnd;
GtkAdjustment *defaultAdjustmentMarginTop;
GtkAdjustment *defaultAdjustmentMarginBottom;
//Globalised variables
GtkWidget *windowChild;
void screenWindowChild() {
    //Init of windowChild
    windowChild = gtk_window_new();
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
}
void screenAddWidget() {
    defaultAdjustmentRow = gtk_adjustment_new(0.0, 0.0, 1000.0, 1.0, 10.0, 0.0);
    defaultAdjustmentColumn = gtk_adjustment_new(0.0, 0.0, 1000.0, 1.0, 10.0, 0.0);
    defaultAdjustmentRowSpan = gtk_adjustment_new(0.0, 0.0, 1000.0, 1.0, 10.0, 0.0);
    defaultAdjustmentColumnSpan = gtk_adjustment_new(0.0, 0.0, 1000.0, 1.0, 10.0, 0.0);
    defaultAdjustmentMinHeight = gtk_adjustment_new(0.0, 0.0, 1000.0, 1.0, 10.0, 0.0);
    defaultAdjustmentMinWidth = gtk_adjustment_new(0.0, 0.0, 1000.0, 1.0, 10.0, 0.0);
    defaultAdjustmentMarginStart = gtk_adjustment_new(0.0, 0.0, 1000.0, 1.0, 10.0, 0.0);
    defaultAdjustmentMarginEnd = gtk_adjustment_new(0.0, 0.0, 1000.0, 1.0, 10.0, 0.0);
    defaultAdjustmentMarginTop = gtk_adjustment_new(0.0, 0.0, 1000.0, 1.0, 10.0, 0.0);
    defaultAdjustmentMarginBottom = gtk_adjustment_new(0.0, 0.0, 1000.0, 1.0, 10.0, 0.0);
    //Init of windowAddWidget
    windowAddWidget = gtk_window_new();
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
    //Init of entrylabel
    entryLabel = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParentWidgets),entryLabel,0,1,10,1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entryLabel),"Enter Widget Label/Placeholder Text");
    //Margins & Paddings
    gtk_widget_set_margin_top(entryLabel,10);
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
    spinbuttonGridPlacementRow = gtk_spin_button_new(defaultAdjustmentRow,1,0);
    gtk_grid_attach(GTK_GRID(gridParentWidgets),spinbuttonGridPlacementRow,1,3,5,1);
    //Init of labelGridPlacementColumn
    GtkWidget *labelGridPlacementColumn = gtk_label_new("Col:");
    gtk_grid_attach(GTK_GRID(gridParentWidgets),labelGridPlacementColumn,6,3,1,1);
    gtk_widget_set_margin_top(labelGridPlacementColumn,4);
    //Init of spinbuttonGridPlacementColumn
    spinbuttonGridPlacementColumn = gtk_spin_button_new(defaultAdjustmentColumn ,1,0);
    gtk_grid_attach(GTK_GRID(gridParentWidgets),spinbuttonGridPlacementColumn,7,3,3,1);
    //Init of labelGridPlacementRowSpan
    GtkWidget *labelGridPlacementRowSpan = gtk_label_new("Height:");
    gtk_grid_attach(GTK_GRID(gridParentWidgets),labelGridPlacementRowSpan,0,4,1,1);
    gtk_widget_set_margin_top(labelGridPlacementRowSpan,4);
    //Init of spinbuttonGridPlacementRowSpan
    spinbuttonGridPlacementRowSpan = gtk_spin_button_new(defaultAdjustmentRowSpan,1,0);
    gtk_grid_attach(GTK_GRID(gridParentWidgets),spinbuttonGridPlacementRowSpan,1,4,5,1);
    gtk_widget_set_margin_top(spinbuttonGridPlacementRowSpan,4);
    //Init of labelGridPlacementColumnSpan
    GtkWidget *labelGridPlacementColumnSpan = gtk_label_new("Width:");
    gtk_grid_attach(GTK_GRID(gridParentWidgets),labelGridPlacementColumnSpan,6,4,1,1);
    gtk_widget_set_margin_top(labelGridPlacementColumnSpan,4);
    //Init of spinbuttonGridPlacementColumnSpan
    spinbuttonGridPlacementColumnSpan = gtk_spin_button_new(defaultAdjustmentColumnSpan ,1,0);
    gtk_grid_attach(GTK_GRID(gridParentWidgets),spinbuttonGridPlacementColumnSpan,7,4,3,1);
    gtk_widget_set_margin_top(spinbuttonGridPlacementColumnSpan,4);
    //Init of labelMinSize
    GtkWidget *labelMinSize = gtk_label_new("Minimum Size:");
    gtk_grid_attach(GTK_GRID(gridParentWidgets),labelMinSize,0,5,6,1);
    gtk_widget_set_halign(labelMinSize,GTK_ALIGN_START);
    gtk_widget_set_margin_start(labelMinSize,6);
    gtk_widget_set_margin_top(labelMinSize,6);
    gtk_widget_set_margin_bottom(labelMinSize,10);
    //Init of labelMinHeight
    GtkWidget *labelMinHeight = gtk_label_new("Height:");
    gtk_grid_attach(GTK_GRID(gridParentWidgets),labelMinHeight,0,6,1,1);
    gtk_widget_set_margin_top(labelMinHeight,4);
    //Init of spinbuttonMinHeight
    spinbuttonMinHeight = gtk_spin_button_new(defaultAdjustmentMinHeight,1,0);
    gtk_grid_attach(GTK_GRID(gridParentWidgets),spinbuttonMinHeight,1,6,5,1);
    gtk_widget_set_margin_top(spinbuttonMinHeight,4);
    //Init of labelMinWidth
    GtkWidget *labelMinWidth = gtk_label_new("Width:");
    gtk_grid_attach(GTK_GRID(gridParentWidgets),labelMinWidth,6,6,1,1);
    gtk_widget_set_margin_top(labelMinWidth,4);
    //Init of spinbuttonMinWidth
    spinbuttonMinWidth = gtk_spin_button_new(defaultAdjustmentMinWidth ,1,0);
    gtk_grid_attach(GTK_GRID(gridParentWidgets),spinbuttonMinWidth,7,6,3,1);
    gtk_widget_set_margin_top(spinbuttonMinWidth,4);
    //Init of labelMargins
    GtkWidget *labelMargins = gtk_label_new("Margin Size for Widget:");
    gtk_grid_attach(GTK_GRID(gridParentWidgets),labelMargins,0,7,10,1);
    gtk_widget_set_halign(labelMargins,GTK_ALIGN_START);
    gtk_widget_set_margin_start(labelMargins,6);
    gtk_widget_set_margin_top(labelMargins,10);
    gtk_widget_set_margin_bottom(labelMargins,10);
    //Init of labelMarginStart
    GtkWidget *labelMarginStart = gtk_label_new("Start:");
    gtk_grid_attach(GTK_GRID(gridParentWidgets),labelMarginStart,0,8,1,1);
    gtk_widget_set_margin_top(labelMarginStart,4);
    //Init of spinbuttonMarginStart
    spinbuttonMarginStart = gtk_spin_button_new(defaultAdjustmentMarginStart,1,0);
    gtk_grid_attach(GTK_GRID(gridParentWidgets),spinbuttonMarginStart,1,8,5,1);
    gtk_widget_set_margin_top(spinbuttonMarginStart,4);
    //Init of labelMarginEnd
    GtkWidget *labelMarginEnd = gtk_label_new("End:");
    gtk_grid_attach(GTK_GRID(gridParentWidgets),labelMarginEnd,6,8,1,1);
    gtk_widget_set_margin_top(labelMarginEnd,4);
    //Init of spinbuttonMarginEnd
    spinbuttonMarginEnd = gtk_spin_button_new(defaultAdjustmentMarginEnd ,1,0);
    gtk_grid_attach(GTK_GRID(gridParentWidgets),spinbuttonMarginEnd,7,8,3,1);
    gtk_widget_set_margin_top(spinbuttonMarginEnd,4);
    //Init of labelMarginTop
    GtkWidget *labelMarginTop = gtk_label_new("Top:");
    gtk_grid_attach(GTK_GRID(gridParentWidgets),labelMarginTop,0,9,1,1);
    gtk_widget_set_margin_top(labelMarginTop,4);
    //Init of spinbuttonMarginTop
    spinbuttonMarginTop = gtk_spin_button_new(defaultAdjustmentMarginTop,1,0);
    gtk_grid_attach(GTK_GRID(gridParentWidgets),spinbuttonMarginTop,1,9,5,1);
    gtk_widget_set_margin_top(spinbuttonMarginTop,4);
    //Init of labelMarginBottom
    GtkWidget *labelMarginBottom = gtk_label_new("Bottom:");
    gtk_grid_attach(GTK_GRID(gridParentWidgets),labelMarginBottom,6,9,1,1);
    gtk_widget_set_margin_top(labelMarginBottom,4);
    //Init of spinbuttonMarginBottom
    spinbuttonMarginBottom = gtk_spin_button_new(defaultAdjustmentMarginBottom ,1,0);
    gtk_grid_attach(GTK_GRID(gridParentWidgets),spinbuttonMarginBottom,7,9,3,1);
    gtk_widget_set_margin_top(spinbuttonMarginBottom,4);
    //Init of buttonAddWidget
    GtkWidget *buttonRegisterWidget = gtk_button_new_with_label("Add Widget");
    gtk_grid_attach(GTK_GRID(gridParentWidgets),buttonRegisterWidget,0,20,10,1);
    g_signal_connect(buttonRegisterWidget,"clicked",G_CALLBACK(registerWidget),NULL);
    //Margins & Paddings
    gtk_widget_set_margin_top(buttonRegisterWidget,10);
}
//It registers/Inputs the values of the widgets and their properties in the widget struct
void  registerWidget() {
    //Function to hold all the logic for when the buttonRegister
    widget[widgetCount].isOccupied = 1;
    strcpy(widget[widgetCount].widgetName,gtk_editable_get_text(GTK_EDITABLE(entryWidgetName)));
    const char *widgetType = gtk_string_list_get_string(GTK_STRING_LIST(listWidgets), gtk_drop_down_get_selected(GTK_DROP_DOWN(dropdownWidgets)));
    strcpy(widget[widgetCount].type.widgetTypeName,widgetType);
    if(strcmp(widget[widgetCount].type.widgetTypeName,"Button")==0){
        strcpy(widget[widgetCount].button.label,gtk_editable_get_text(GTK_EDITABLE(entryLabel)));
        widget[widgetCount].type.isButton = 1;
    }
    else if(strcmp(widgetType,"Label")==0){
        strcpy(widget[widgetCount].label.label,gtk_editable_get_text(GTK_EDITABLE(entryLabel)));
        widget[widgetCount].type.isLabel = 1;
    }
    else if(strcmp(widgetType,"Entry")==0) {
        widget[widgetCount].type.isEntry = 1;
        if (strcmp(gtk_editable_get_text(GTK_EDITABLE(entryLabel)),"")!=0){
            strcpy(widget[widgetCount].entry.placeholderText,gtk_editable_get_text(GTK_EDITABLE(entryLabel)));
            widget[widgetCount].entry.hasPlaceHolderText = 1;
        }
    }else if(strcmp(widgetType,"T.View")==0){
        widget[widgetCount].type.isTextView = 1;
    }
        widget[widgetCount].grid.row = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonGridPlacementRow));
        widget[widgetCount].grid.col = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonGridPlacementColumn));
        widget[widgetCount].grid.rowSpan = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonGridPlacementRowSpan));
        widget[widgetCount].grid.colSpan = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonGridPlacementColumnSpan));
    //Checks if colspan and rowspan is 0 or less and defaults the value to -1 if that's the case
        if (widget[widgetCount].grid.rowSpan<=0 && widget[widgetCount].grid.colSpan<=0) {
            widget[widgetCount].grid.rowSpan=1;
            widget[widgetCount].grid.colSpan=1;
        }else if (widget[widgetCount].grid.rowSpan<=0) {
            widget[widgetCount].grid.rowSpan=1;
        }else if (widget[widgetCount].grid.colSpan<=0) {
            widget[widgetCount].grid.colSpan=1;
        }
        widget[widgetCount].minSize.height = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonMinHeight));
        widget[widgetCount].minSize.width = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonMinWidth));
        //checks if min height or width is 0 or less if so defaults it to -1
        if (widget[widgetCount].minSize.height<=0 && widget[widgetCount].minSize.width<=0) {
            widget[widgetCount].minSize.height=-1;
            widget[widgetCount].minSize.width=-1;
        }else if (widget[widgetCount].minSize.height<=0) {
            widget[widgetCount].minSize.height=-1;
        }else if (widget[widgetCount].minSize.width<=0) {
            widget[widgetCount].minSize.width=-1;
        }
        //Reads and stores the margin values
        widget[widgetCount].margin.top = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonMarginTop));
        widget[widgetCount].margin.bottom = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonMarginBottom));
        widget[widgetCount].margin.start = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonMarginStart));
        widget[widgetCount].margin.end = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonMarginEnd));
        //Increases the widgetCount as more widgets are added
        widgetCount++;
        gtk_window_destroy(GTK_WINDOW(windowAddWidget));
        declareWidgetLabels();
    }
    //Globalization of variables
    GtkWidget *scrolledWindowWidgets;
    GtkWidget *gridWidgets;
    static void activate(GtkApplication *app,gpointer user_data){
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
        g_signal_connect(buttonChildWindow,"clicked",G_CALLBACK(screenWindowChild),NULL);
        //init of gridParent
        GtkWidget *gridParent = gtk_grid_new();
        gtk_window_set_child(GTK_WINDOW(windowMain),gridParent);
        //Margins & Paddings
        gtk_widget_set_margin_start(gridParent,10);
        gtk_widget_set_margin_end(gridParent,10);
        gtk_widget_set_margin_top(gridParent,10);
        gtk_widget_set_margin_bottom(gridParent,10);
        gtk_widget_set_halign(gridParent,GTK_ALIGN_CENTER);
        gtk_widget_set_valign(gridParent,GTK_ALIGN_CENTER);
        //init of labelWidgets
        GtkWidget *labelWidgets = gtk_label_new("Widgets");
        gtk_grid_attach(GTK_GRID(gridParent),labelWidgets,0,0,10,1);
        //Init of scrolledWindowWidgets
        scrolledWindowWidgets = gtk_scrolled_window_new();
        gtk_grid_attach(GTK_GRID(gridParent),scrolledWindowWidgets,0,1,10,10);
        gtk_widget_set_size_request(scrolledWindowWidgets,380,400);
        //Init of gridScrolledWindow
        gridWidgets = gtk_grid_new();
        gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolledWindowWidgets),gridWidgets);
        //Init of buttonExportGui
        GtkWidget *buttonExportGui = gtk_button_new_with_label("Export");
        gtk_grid_attach(GTK_GRID(gridParent),buttonExportGui,0,12,10,1);
        g_signal_connect(buttonExportGui,"clicked",G_CALLBACK(exportGui),NULL);
        gtk_widget_set_size_request(buttonExportGui,400,-1);
    }
    void declareWidgetLabels() {
        //Removes the old widgets
        GtkWidget *child;
        while ((child = gtk_widget_get_first_child(GTK_WIDGET(gridWidgets))) != NULL) {
            gtk_grid_remove(GTK_GRID(gridWidgets), child);
        }
        //Adds plaques/Labels for widgets with some of their info
        for (int i=0; i < widgetCount; i++) {
            //checks if the widget is occupied
            if (widget[i].isOccupied==1){
                //Init of boxWidgetInfo
                widget[i].boxWidgetInfo = gtk_center_box_new();
                gtk_orientable_set_orientation(GTK_ORIENTABLE(widget[i].boxWidgetInfo),GTK_ORIENTATION_HORIZONTAL);
                gtk_grid_attach(GTK_GRID(gridWidgets),widget[i].boxWidgetInfo,0,i,1,1);
                gtk_widget_set_size_request(widget[i].boxWidgetInfo,380,-1);
                //init of labelWidgetinfo
                char widgetInfo[200];
                snprintf(widgetInfo,sizeof(widgetInfo),"%s \n"
                                                       "Widget Type: %s \n"
                                                       "Grid Placement: %d %d",
                                                       widget[i].widgetName,
                                                       widget[i].type.widgetTypeName,
                                                       widget[i].grid.row,
                                                       widget[i].grid.col);
                widget[i].labelWidgetInfo = gtk_label_new(widgetInfo);
                gtk_center_box_set_start_widget(GTK_CENTER_BOX(widget[i].boxWidgetInfo),widget[i].labelWidgetInfo);
                gtk_widget_set_halign(widget[i].labelWidgetInfo,GTK_ALIGN_START);

                //Init of buttonDeleteWidget
                widget[i].buttonDeleteWidget = gtk_button_new_with_label("❌");
                gtk_center_box_set_end_widget(GTK_CENTER_BOX(widget[i].boxWidgetInfo),widget[i].buttonDeleteWidget);
                g_signal_connect(widget[i].buttonDeleteWidget,"clicked",G_CALLBACK(deleteWidget),GINT_TO_POINTER(i));
            }
        }
    }
    //Overrites the widget that is to be deleted with the succeeding widget and soon
    void deleteWidget(GtkButton *button, gpointer user_data){
        int i = GPOINTER_TO_INT(user_data);
        for (int j = i; j!=widgetCount ; j++) {
            widget[j] = widget[j+1];
        }
        declareWidgetLabels();
        widgetCount--;
    }

    void exportGui() {
        //Writes the widget data in binary for other program to read
        FILE *file1 = fopen("ExportedGui/build/widget.data","w");
        fwrite(&widgetCount,sizeof(widgetCount),1,file1);
        fwrite(&widget,sizeof(widget),widgetCount,file1);
        fclose(file1);

        //Writes the data in a documentation style for a hooman to read
        FILE *file2 = fopen("ExportedGui/build/WidgetDocumentation.txt","w");
        fprintf(file2,"S.N. \t Widget Name \t Widget Type \t Row \t Row Span \t Column \t Column Span \t Min Width \t Min Height \t Margin Top \t Margin Bottom \t Margin Start \t Margin End \n");
        for (int i =0; i<widgetCount;i++) {
            fprintf(file2,"%d \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n",
                i+1,
                widget[i].widgetName,
                widget[i].type.widgetTypeName,
                widget[i].grid.row,
                widget[i].grid.rowSpan,
                widget[i].grid.col,
                widget[i].grid.colSpan,
                widget[i].minSize.width,
                widget[i].minSize.height,
                widget[i].margin.top,
                widget[i].margin.bottom,
                widget[i].margin.start,
                widget[i].margin.end);
        }
    fclose(file2);
    }
    //Declares the widget in the struct according to the information and configurations provided
    void declareWidgets() {
        //Sets the widgets as null
        int i=0;
        while (widget[i].widget!=NULL) {
            widget[i].widget=NULL;
            i++;
        }
        //This Part   actualy does the comparing and declaring
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
            //Registering the Margins values
            gtk_widget_set_margin_top(widget[j].widget,widget[j].margin.top);
            gtk_widget_set_margin_bottom(widget[j].widget,widget[j].margin.bottom);
            gtk_widget_set_margin_start(widget[j].widget,widget[j].margin.start);
            gtk_widget_set_margin_end(widget[j].widget,widget[j].margin.end);
        }
    }
    int main(int argc, char **argv) {
        GtkApplication *app= gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
        g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
        int status = g_application_run (G_APPLICATION (app), argc, argv);
        g_object_unref (app);
        return status;
    }

