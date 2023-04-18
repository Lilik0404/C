#include <gtk/gtk.h>

  GtkWidget * window;
  GtkWidget * vbox;
  GtkWidget * image, * image1, * image2;
  GtkWidget * toolbar;
  GtkToolItem * btn1, * btn2, * btn3;
static void on_window_destroy(GtkWidget *widget, gpointer data) {
    GtkWidget *toggle_button = (GtkWidget *)data;
    gtk_toggle_tool_button_set_active(btn1,FALSE);
     GtkWidget **window_ptr = (GtkWidget **)data;
    *window_ptr = NULL;
}
static void on_window_destroy1(GtkWidget *widget, gpointer data) {
    gtk_toggle_tool_button_set_active(btn2,FALSE);
     GtkWidget **window_ptr = (GtkWidget **)data;
    *window_ptr = NULL;
}
static void on_window_destroy2(GtkWidget *widget, gpointer data) {
     gtk_toggle_tool_button_set_active(btn3,FALSE);
     GtkWidget **window_ptr = (GtkWidget **)data;
    *window_ptr = NULL;
}
static void on_button_clicked(GtkWidget * button, gpointer data) {
    
   static GtkWidget * window=NULL;
    if(window!=NULL)
        {
            gtk_widget_destroy(window);
        }
     else{
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(window), "window from button 1");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
     g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(on_window_destroy), & window);

    gtk_widget_show_all(window);
     }   
}

static void on_button_clicked1(GtkWidget * button, gpointer data){
    static GtkWidget * window=NULL;
    if(window!=NULL)
        {
            gtk_widget_destroy(window);
        }
     else{
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(window), "window from button 2");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(on_window_destroy1), & window);

    gtk_widget_show_all(window);
     }   
}

static void on_button_clicked2(GtkWidget * button, gpointer data){
   static GtkWidget * window=NULL;
    if(window!=NULL)
        {
            gtk_widget_destroy(window);
        }
     else{
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(window), "window from button 3");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(on_window_destroy2), & window);

    gtk_widget_show_all(window);
     }   
}

int main(int argc, char * argv[]) {


  gtk_init( & argc, & argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
  gtk_window_set_title(GTK_WINDOW(window), "spooooon");
  gtk_widget_modify_bg(window, GTK_STATE_NORMAL, 0xffff);
  vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window), vbox);
  g_signal_connect(G_OBJECT(window), "destroy",
    G_CALLBACK(gtk_main_quit), NULL);

  toolbar = gtk_toolbar_new();
  gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_BOTH);

  image = gtk_image_new_from_file("button.png");
  image1 = gtk_image_new_from_file("button2.png");
  image2 = gtk_image_new_from_file("button3.png");

  btn1 = gtk_toggle_tool_button_new();
  btn2 = gtk_toggle_tool_button_new();
  btn3 = gtk_toggle_tool_button_new();
  gtk_tool_button_set_label(btn1,"button1");
  gtk_tool_button_set_label(btn2,"button2");
  gtk_tool_button_set_label(btn3,"button3");
  gtk_tool_button_set_icon_widget(GTK_TOGGLE_TOOL_BUTTON(btn1), image);  
  gtk_tool_button_set_icon_widget(GTK_TOGGLE_TOOL_BUTTON(btn2), image1);  
  gtk_tool_button_set_icon_widget(GTK_TOGGLE_TOOL_BUTTON(btn3), image2);  
  g_signal_connect(btn1, "clicked", G_CALLBACK(on_button_clicked), NULL);
  g_signal_connect(btn2, "clicked", G_CALLBACK(on_button_clicked1), NULL);
  g_signal_connect(btn3, "clicked", G_CALLBACK(on_button_clicked2), NULL);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), btn1, -1);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), btn2, -1);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), btn3, -1);

  gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 5);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
