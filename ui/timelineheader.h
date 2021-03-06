#ifndef TIMELINEHEADER_H
#define TIMELINEHEADER_H

#include <QWidget>
#include <QFontMetrics>
class QScrollArea;
class Viewer;

class TimelineHeader : public QWidget
{
    Q_OBJECT
public:
	explicit TimelineHeader(QWidget *parent = 0);
    void set_in_point(long p);
    void set_out_point(long p);

	Viewer* viewer;

	bool snapping;

	void show_text(bool enable);
	void update_zoom(double z);
	void delete_markers();

public slots:
	void set_scroll(int);
	void set_visible_in(long i);

protected:
	void paintEvent(QPaintEvent*);
	void mousePressEvent(QMouseEvent*);
	void mouseMoveEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);
	void focusOutEvent(QFocusEvent*);

private:
	void update_parents();

    bool dragging;

    bool resizing_workarea;
    bool resizing_workarea_in;
    long temp_workarea_in;
    long temp_workarea_out;
    long sequence_end;

	double zoom;

    long in_visible;

	void set_playhead(int mouse_x);

    QFontMetrics fm;

	int drag_start;
	bool dragging_markers;
	QVector<int> selected_markers;
	QVector<long> selected_marker_original_times;

	long getHeaderFrameFromScreenPoint(int x);
	int getHeaderScreenPointFromFrame(long frame);

	int scroll;

	int height_actual;
	bool text_enabled;

signals:
};

#endif // TIMELINEHEADER_H
