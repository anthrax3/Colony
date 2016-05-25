/**
 *   @file: RenderItem.h
 *
 *   @date: May 20, 2016
 * @author: Mateusz Midor
 */

#ifndef SOURCE_RENDERITEM_H_
#define SOURCE_RENDERITEM_H_

class RenderItem {
public:
	RenderItem();
	virtual ~RenderItem();

	/**
	 * @name	update
	 * @brief	Eg. animate Milkshape3D model
	 * @param 	dt DeltaTime
	 */
	virtual void update(const float dt) = 0;

	/**
	 * @name	prepareRenderSnashot
	 * @brief	Eg. copy Milkshape3D skinned vertices to separate buffer for rendering
	 */
	virtual void prepareRenderSnashot() = 0;

	/**
	 * @name	render
	 * @brief	Eg. render the Milkshape3D model using OpenGl calls
	 * @note	The model being rendered can't be the same data that is updated by "update" (threading)
	 */
	virtual void render() = 0;
};

#endif /* SOURCE_RENDERITEM_H_ */
