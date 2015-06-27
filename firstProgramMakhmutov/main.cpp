#include <gtk/gtk.h>
#include <iostream>

using namespace std;

void onActivate(GtkApplication *app, gpointer user_data){
    GtkWidget *window=gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window),"Hello, world!");
    gtk_widget_show_all(window);
}

int main(){
    GtkApplication *app;
    app = gtk_application_new(0,G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app,"activate",G_CALLBACK(onActivate),0);
    int status=g_application_run(G_APPLICATION(app),0,0);
    g_object_unref(app);
    return status;
}