#ifndef INPUTARRAY_H
#define INPUTARRAY_H

#include "input.h"

class NodeInputArray : public NodeInput
{
  Q_OBJECT
public:
  NodeInputArray(const QString &id, const DataType& type, const QVariant& default_value = 0);

  virtual bool IsArray() override;

  int GetSize() const;

  void Prepend();
  void Append();
  void InsertAt(int index);
  void RemoveLast();
  void RemoveAt(int index);
  void SetSize(int size, bool lock = true);

  int IndexOfSubParameter(NodeInput* input) const;

  NodeInput* First() const;
  NodeInput* Last() const;
  NodeInput* At(int index) const;

  const QVector<NodeInput*>& sub_params();

signals:
  void SizeChanged(int size);

private:
  QVector<NodeInput*> sub_params_;

  QVariant default_value_;

};

#endif // INPUTARRAY_H
